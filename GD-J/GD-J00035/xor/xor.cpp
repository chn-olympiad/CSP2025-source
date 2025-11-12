#include<bits/stdc++.h>
const int N=5e5+10;
int a[N],pre[N];
long long query(int l,int r){
	return pre[l-1] xor pre[r];
}
bool cmp(std::pair<int,int> x,std::pair<int,int> y){
	return x.second>y.second;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	std::cin>>n>>k;
	bool sp=true;
	int c[2]={};
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
		if(sp!=1 and sp!=0)sp=false;
		else c[a[i]]++;
		pre[i]=pre[i-1] xor a[i];
//		std::cout<<pre[i]<<" ";
	} 
//	std::cout<<std::endl;
	if(sp){
		if(k==1)std::cout<<c[1];
		else {
			std::cout<<c[0]+c[1]/2;
		}
	}
	else {
		std::vector<std::pair<int,int> >can;
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				if(query(i,j)==k){
				can.push_back({i,j});
//			std::cout<<i<<" "<<j<<" "<<k<<std::endl;
				}
			}
		}
//	std::cout<<std::endl;
		sort(can.begin(),can.end(),cmp);
		int ans=1;
		std::map<std::pair<int,int>,int >vis;
		for(int i=0;i<can.size();i++){
			for(int j=can.size()-1;j>i;j--){
				if(can[i].first >can[j].second){
					if(!vis[{i,j}]){
						vis[{i,j}]=1;
						ans++;
					//std::cout<<i<<" "<<j<<std::endl;
					}
				}
			}
		}
		std::cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
