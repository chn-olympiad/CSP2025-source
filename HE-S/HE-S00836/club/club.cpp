#include <bits/stdc++.h>
using namespace std;
int T,n;
struct asd{
	long long a,b,c;
}v[100100],u[100100],z[100100];
bool cmp1(asd a,asd b){
	return a.a>b.a;
}
bool cmp2(asd a,asd b){
	return a.b>b.b;
}
bool cmp3(asd a,asd b){
	return a.c>b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin >>T;
	while(T--){
	long long ans=0,cnt=0,sum=0;
		cin >>n;
		for(int i=1;i<=n;i++){
			cin >>v[i].a>>v[i].b>>v[i].c;
			u[i].a=v[i].a;
			u[i].b=v[i].b;
			u[i].c=v[i].c;
			z[i].a=v[i].a;
			z[i].b=v[i].b;
			z[i].c=v[i].c;
		}
		if(n==2){
			cout <<max(v[1].a+v[2].b,max(v[1].a+v[2].c,max(v[1].b+v[2].a,max(v[1].b+v[2].c,max(v[1].c+v[2].a,v[1].c+v[2].b)))));
			break;
		}
		sort(u+1,u+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			if(u[i].a==-1){
				break;
			}
			if((u[i].a<u[i].b)||(u[i].a<u[i].c)){
				u[i].a=-1;
				continue;
			}
			ans+=u[i].a;
			u[i].a=-1,u[i].b=-1,u[i].c=-1;
		}
		sort(u+1,u+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			if(u[i].b==-1){
				break;
			}
			if(u[i].c>u[i].b){
				u[i].b=-1;
				continue;
			}
			ans+=u[i].b;
			u[i].a=-1,u[i].b=-1,u[i].c=-1;
		}
		sort(u+1,u+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			if(u[i].c==-1){
				break;
			}
			ans+=u[i].c;
			u[i].a=-1,u[i].b=-1,u[i].c=-1;
		}
		sort(v+1,v+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			if(v[i].b==-1){
				break;
			}
			if(v[i].c>v[i].b||v[i].a>v[i].b){
				v[i].b=-1;
				continue;
			}
			cnt+=v[i].b;
			v[i].a=-1,v[i].b=-1,v[i].c=-1;
		}
		sort(v+1,v+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			if(v[i].a==-1){
				break;
			}
			if((v[i].a<v[i].b)||(v[i].a<v[i].c)){
				v[i].a=-1;
				continue;
			}
			cnt+=v[i].a;
			v[i].a=-1,v[i].b=-1,v[i].c=-1;
		}
		sort(v+1,v+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			if(v[i].c==-1){
				break;
			}
			cnt+=v[i].c;
			v[cnt].a=-1,v[i].b=-1,v[i].c=-1;
		}
		sort(z+1,z+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			if(z[i].c==-1){
				break;
			}
			if(z[i].a>z[i].c||z[i].b>z[i].c){
				z[i].c=-1;
				continue;
			}
			sum+=z[i].c;
			z[cnt].a=-1,z[i].b=-1,z[i].c=-1;
		}
		sort(z+1,z+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			if(z[i].b==-1){
				break;
			}
			if(z[i].c>z[i].b||z[i].a>z[i].b){
				z[i].b=-1;
				continue;
			}
			sum+=z[i].b;
			z[i].a=-1,z[i].b=-1,z[i].c=-1;
		}
		sort(z+1,z+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			if(z[i].a==-1){
				break;
			}
			if((z[i].a<z[i].b)||(z[i].a<z[i].c)){
				z[i].a=-1;
				continue;
			}
			sum+=z[i].a;
			z[i].a=-1,z[i].b=-1,z[i].c=-1;
		}
		
		cout <<max(max(ans,cnt),sum)<<endl;
	}
	return 0;
}
