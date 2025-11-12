#include<bits/stdc++.h>
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	std::cin>>n>>m;
	std::vector<int> a(n*m+1);
	int cnt=1;
	for(int i=1;i<=n*m;i++){
		std::cin>>a[i];
		int r=a[1];
		if(a[i]>r)cnt++;
	}
	int seat[15][15]={};
	std::map<int,std::pair<int,int> > mp;
	int idx=1;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2)mp[idx++]={i,j};
			else mp[idx++]={i,n+1-j};
		}
	}

	std::cout<<mp[cnt].first<<" "<<mp[cnt].second;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
