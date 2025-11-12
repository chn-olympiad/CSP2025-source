#include<bits/stdc++.h>
using namespace std;
long long n,wer;
struct man{
	int one,two,three,M;
};
man a[1000010];
int Max(int q,int w,int e){
	return max(max(q,w),e);
}
bool cmpone(man x,man y){
	return x.M-max(x.two,x.three)<y.M-max(y.two,y.three);
}
bool cmptwo(man x,man y){
	return x.M-max(x.one,x.three)<y.M-max(y.one,y.three);
}
bool cmpthree(man x,man y){
	return x.M-max(x.two,x.one)<y.M-max(y.two,y.one);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	int k1,k2,k3;
	for(int oioi=1;oioi<=t;oioi+=1) {
		cin>>n;
		wer=0;
		k1=0;
		k2=0;
		k3=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i].one>>a[i].two>>a[i].three;
			a[i].M=Max(a[i].two,a[i].three,a[i].one);
			if(a[i].M==a[i].one)k1++;
			else if(a[i].M==a[i].two)k2++;
			else k3++;
			wer+=a[i].M;
		}
		if(k1>n/2){
			sort(a+1,a+1+n,cmpone);
			for(int i=1;k1>n/2;i++){
				if(a[i].M==a[i].one){
					k1--;
					wer-=a[i].M;
					wer+=max(a[i].two,a[i].three);
				}
			}
		}
		else if(k2>n/2){
			sort(a+1,a+1+n,cmptwo);
			for(int i=1;k2>n/2;i++){
				if(a[i].M==a[i].two){
					k1--;
					wer-=a[i].M;
					wer+=max(a[i].one,a[i].three);
				}
			}
		}
		else if(k3>n/2){
			sort(a+1,a+1+n,cmpthree);
			for(int i=1;k3>n/2;i++){
				if(a[i].M==a[i].three){
					k1--;
					wer-=a[i].M;
					wer+=max(a[i].two,a[i].one);
				}
			}
		}
		cout<<wer<<endl;
	}
	return 0;
}
