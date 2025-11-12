#include<bits/stdc++.h>
using namespace std;
int T,n,f;
struct pt{
	int v[4],t[4],vm,tm;
}a[100005]; 
bool cmp1(pt a,pt b){
	return a.v[1]<b.v[1];
}
bool cmp2(pt a,pt b){
	return a.v[2]<b.v[2];
}
bool cmp3(pt a,pt b){
	return a.v[3]<b.v[3];
}
bool cmp4(int s,int b){
	return a[s].t[f]>a[b].t[f];
}
int main(){
  	freopen("club.in","r",stdin);
  	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int sum=0;
		vector<int>c[4];
		cin>>n;
		for(int i=1;i<=n;i++)
	 		for(int j=1;j<=3;j++)
				cin>>a[i].v[j];
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++)a[i].t[1]=i;
		sort(a+1,a+n+1,cmp2);
		for(int i=1;i<=n;i++)a[i].t[2]=i;
		sort(a+1,a+n+1,cmp3);
		for(int i=1;i<=n;i++)a[i].t[3]=i;
		for(int i=1;i<=n;i++)a[i].vm=max_element(a[i].v+1,a[i].v+4)-a[i].v;
		for(int i=1;i<=n;i++)a[i].tm=max_element(a[i].t+1,a[i].t+4)-a[i].t;
		for(int i=1;i<=n;i++){
			sum+=a[i].v[a[i].vm];
			c[a[i].vm].push_back(i);
		}
		f=0;
		for(int i=1;i<=3;i++){
			if(c[i].size()>n/2){
				f=i;
				break;
			}
		}
		if(!f){
			cout<<sum<<endl;
		}
		else {
			while(c[1].size()>n/2||c[2].size()>n/2||c[3].size()>n/2){
				if(c[1].size()>n/2)f=1;
				if(c[2].size()>n/2)f=2;
				if(c[3].size()>n/2)f=3;
				int ll=c[f].size()-n/2;
				sort(c[f].begin(),c[f].end(),cmp4);
				for(int i=1;i<=ll;i++){
					pt ls=a[c[f][c[f].size()-1]];
					if(f==1){
						if(ls.v[2]>=ls.v[3]){
							c[2].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[1]+ls.v[2];
						}else{
							c[3].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[1]+ls.v[3];
						}
					}
					if(f==2){
						if(ls.v[1]>=ls.v[3]){
							c[1].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[2]+ls.v[1];
						}else{
							c[3].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[2]+ls.v[3];
						}
					}
					if(f==3){
						if(ls.v[1]>=ls.v[2]){
							c[1].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[3]+ls.v[1];
						}else{
							c[2].push_back(c[f][c[f].size()-1]);
							sum=sum-ls.v[3]+ls.v[2];
						}
					}
					c[f].pop_back();
				}
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}

