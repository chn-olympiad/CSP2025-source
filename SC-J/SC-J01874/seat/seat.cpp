#include<bits/stdc++.h>
using namespace std;
#define int long long
int b,c,d,e;
struct qwe{
	int w,s;
};qwe a[1005];
bool cmp(qwe x1,qwe x2){
	return x1.w>x2.w;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=1000;i++) a[i].s=0;
	cin>>b>>c;
	cin>>a[1].w;
	a[1].s=1;
	for(int i=2;i<=b*c;i++) cin>>a[i].w;
	sort(a+1,a+b*c+1,cmp);
	for(int i=1;i<=b*c;i++){
		if(a[i].s==1){
			e=i/b;
			if(e%2==1&&i%b==0) cout<<i/b<<' '<<b;
			else if(e%2==1&&i%b!=0) cout<<i/b+1<<' '<<b-i%b+1;
			else if(e%2==0&&i%b==0) cout<<i/b<<' '<<1;
			else if(e%2==0&&i%b!=0) cout<<i/b+1<<' '<<i%b;
			return 0;
		}
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}