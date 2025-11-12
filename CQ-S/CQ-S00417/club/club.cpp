#include<bits/stdc++.h>
using namespace std;
int t,n,h,a,b,c,ii;
struct g{
	int a,b,c;
}s[(int)1e5+5];
int f(int i,int a,int b,int c,int k){
	if(i>=n)return k;
	if(a<n/2&&b<n/2&&c<n/2)
	return(max(f(i+1,a+1,b,c,k+s[i].a),max(f(i+1,a,b+1,c,k+s[i].b),f(i+1,a,b,c+1,k+s[i].c))));
	if(a<n/2&&b<n/2)
	return(max(f(i+1,a+1,b,c,k+s[i].a),f(i+1,a,b+1,c,k+s[i].b)));
	if(b<n/2&&c<n/2)
	return(max(f(i+1,a,b,c+1,k+s[i].c),f(i+1,a,b+1,c,k+s[i].b)));
	return(max(f(i+1,a+1,b,c,k+s[i].a),f(i+1,a,b,c+1,k+s[i].c)));
}
int c0(g x,g y){
	return(max(x.a,max(x.b,x.c))>max(y.a,max(y.b,y.c)));
}
int c1(g x,g y){
	return(max(x.a,x.b)>max(y.a,y.b));
}
int c2(g x,g y){
	return(max(x.a,x.c)>max(y.a,y.c));
}
int c3(g x,g y){
	return(max(x.c,x.b)>max(y.c,y.b));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++)cin>>s[i].a>>s[i].b>>s[i].c;
		if(n<=10){
			cout<<f(0,0,0,0,0)<<endl;
			continue;
		}
		h=0,a=0,b=0,c=0,ii=0;
		sort(s,s+n,c0);
		for(int i=0;i<n;i++){
			if(max(s[i].a,max(s[i].b,s[i].c))==s[i].a){
				h+=s[i].a;
				a++;
			}
			else if(max(s[i].a,max(s[i].b,s[i].c))==s[i].b){
				h+=s[i].b;
				b++;
			}
			else{
				h+=s[i].c;
				c++;
			}
			if(a==n/2||b==n/2||c==n/2){
				ii=i+1;
				break;
			}
		}
		if(ii){
			if(a==n/2){
				sort(s+ii,s+n,c3);
				for(int i=ii;i<n;i++)h+=max(s[i].b,s[i].c);
			}
			else if(b==n/2){
				sort(s+ii,s+n,c2);
				for(int i=ii;i<n;i++)h+=max(s[i].a,s[i].c);
			}
			else{
				sort(s+ii,s+n,c1);
				for(int i=ii;i<n;i++)h+=max(s[i].a,s[i].b);
			}
		}
		cout<<h<<endl;
	}
}
