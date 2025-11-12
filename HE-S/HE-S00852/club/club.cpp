#include<bits/stdc++.h>
using namespace std;
int n,m,b,h,a=1,s=1,d=1,v[100010],l[100010],k[100010];
bool qwe(int q,int w){
	return q>w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>m;
		int u=m;
		for(int i=1;i<=m;i++){
			cin>>v[i]>>l[i]>>k[i];
		}sort(v+1,v+1+m,qwe);
		sort(l+1,l+1+m,qwe);
		sort(k+1,k+1+m,qwe);
		if(m/2>1){
			for(int j=1;j<=m/2;j++){
				if(u>3){
					h+=v[j];
					h+=l[j];
					h+=k[j];
					u-=3;
				}else{
					int o=v[j]+l[j]+k[j];
					int g=max(v[j],max(l[j],k[j]));
					int f=min(v[j],min(l[j],k[j]));
					h+=g;
					if(u==2){
						h+=o-f-g;
					}
				}
			}
		}else{
			if(v[2]!=0){
				h+=v[2]+max(l[1],k[1]);
			}if(l[2]!=0){
				h+=l[2]+max(k[1],v[1]);
			}if(k[2]!=0){
				h+=k[2]+max(v[1],l[1]);
			}
		}cout<<h;
		h=0;
	}
	
	
	return 0;
}
