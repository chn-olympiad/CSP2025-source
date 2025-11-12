#include<bits/stdc++.h>
using namespace std;
struct co{
	long long maxn,mid,minn;
	char sum1,sum2,sum3;
}s[1000024];
long long t,n,ans;
bool coke(co v,co w){
	if(v.maxn>w.maxn)return 1;
	if(v.maxn==w.maxn&&v.mid>w.mid)return 1;
	if(v.maxn==w.maxn&&v.mid==w.mid&&v.minn>=w.minn)return 1;
	return 0;	
}int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				s[i].maxn=x;
				s[i].sum1='a';
				if(y>=z){
					s[i].mid=y;
					s[i].sum2='b';
					s[i].minn=z;
					s[i].sum3='c';
				}else{
					s[i].mid=z;
					s[i].sum2='c';
					s[i].minn=y;
					s[i].sum3='b';
				}
			}if(x<y&&y>=z){
				s[i].maxn=y;
				s[i].sum1='b';
				if(x>=z){
					s[i].mid=x;
					s[i].sum2='a';
					s[i].minn=z;
					s[i].sum3='c';
				}else{
					s[i].mid=z;
					s[i].sum2='c';
					s[i].minn=x;
					s[i].sum3='a';
				}
			}if(x<z&&y<z){
				s[i].maxn=z;
				s[i].sum1='c';
				if(x>=y){
					s[i].mid=x;
					s[i].sum2='a';
					s[i].minn=y;
					s[i].sum3='b';
				}else{
					s[i].mid=y;
					s[i].sum2='b';
					s[i].minn=x;
					s[i].sum3='a';
				}
			}
		}sort(s+1,s+1+n,coke);
		long long k=n/2,x=0,y=0,z=0,an=0;
		for(int i=1;i<=n;i++){
			if(s[i].sum1=='a'){
				if(x<k){
					x++;
					an+=s[i].maxn;
				}else{
					if(s[i].sum2=='b'){
						if(y<k){
							y++;
							an+=s[i].mid;
						}else{
							z++;
							an+=s[i].minn;
						}
					}if(s[i].sum2=='c'){
						if(z<k){
							z++;
							an+=s[i].mid;
						}else{
							y++;
							an+=s[i].minn;
						}
					}
				}
			}else if(s[i].sum1=='b'){
				if(y<k){
					y++;
					an+=s[i].maxn;
				}else{
					if(s[i].sum2=='a'){
						if(x<k){
							x++;
							an+=s[i].mid;
						}else{
							z++;
							an+=s[i].minn;
						}
					}if(s[i].sum2=='c'){
						if(z<k){
							z++;
							an+=s[i].mid;
						}else{
							x++;
							an+=s[i].minn;
						}
					}
				}
			}else{
				if(z<k){
					z++;
					an+=s[i].maxn;
				}else{
					if(s[i].sum2=='a'){
						if(x<k){
							x++;
							an+=s[i].mid;
						}else{
							y++;
							an+=s[i].minn;
						}
					}if(s[i].sum2=='b'){
						if(y<k){
							y++;
							an+=s[i].mid;
						}else{
							x++;
							an+=s[i].minn;
						}
					}
				}
			}
		}cout<<an<<endl;
	}return 0;
} 
