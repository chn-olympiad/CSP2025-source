#include<bits/stdc++.h>
using namespace std;
struct node{
	int i5,i2,i3,c;
}a[100005];
long long n,t,cnt=0,c1=0,c2=0,c3=0;
bool f1=1,f2=1,f3=1;
int maxx(int x,int y,int z){
	return max(max(x,y),max(x,z));
}
int minx(int x,int y,int z){
	return min(min(x,y),min(x,z));
}
bool cmp(node x,node y){

	return x.c>y.c;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt=0,c1=0,c2=0,c3=0,f1=1,f2=1,f3=1;
		cin>>n;
		int k;
		for(int i=1;i<=n;i++) cin>>a[i].i5>>a[i].i2>>a[i].i3;
		for(int i=1;i<=n;i++){
			if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i5 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i5) k=a[i].i5;
			if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i2 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i2) k=a[i].i2;
			if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i3 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i3) k=a[i].i3;
			a[i].c=maxx(a[i].i5,a[i].i2,a[i].i3)-k;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i5 && f1){
				c1++,cnt+=a[i].i5;
			}
			else if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i2 && f2){
				c2++,cnt+=a[i].i2;
			} 
			else if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i3 && f3){
				c3++,cnt+=a[i].i3;
			}
			else if((f1&&f2)||(f3&&f2)||(f1&&f3)){
				if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i5 && f1) c1++,cnt+=a[i].i5;
				else if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i2 && f2) c2++,cnt+=a[i].i2;
				else if(maxx(a[i].i5,a[i].i2,a[i].i3)==a[i].i3 && f3) c3++,cnt+=a[i].i3;
				else if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i5 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i5 && f1) c1++,cnt+=a[i].i5;
				else if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i2 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i2 && f2) c2++,cnt+=a[i].i2;
				else if(maxx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i3 && minx(a[i].i5,a[i].i2,a[i].i3)!=a[i].i3 && f3) c3++,cnt+=a[i].i3;
				else{
					if(f1) c1++,cnt+=a[i].i5;
					else if(f2) c2++,cnt+=a[i].i2;
					else if(f3) c3++,cnt+=a[i].i3;
				}
			}else{
				if(f1) c1++,cnt+=a[i].i5;
				else if(f2) c2++,cnt+=a[i].i2;
				else if(f3) c3++,cnt+=a[i].i3;
			}
			if(c1==n/2) f1=0;
			if(c2==n/2) f2=0;
			if(c3==n/2) f3=0;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
