#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int t;
struct b{
	int a1,a2,a3;
};
b a[N];
bool cmp(b A,b B){
	if(A.a1<B.a1) return 0;
	else return 1;
}bool cmp2(b A,b B){
	if(A.a1<B.a2) return 0;
	else return 1;
}
bool cmp3(b A,b B){
	if(A.a1<B.a3) return 0;
	else return 1;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,b[N];
		int s=n;
		cin>>n;
		for(int i=1;i<=n;i++){
			b[i]=1;
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		if(n==1){
			cout<<max(a[1].a1,max(a[1].a2,a[1].a3))<<endl;
		}
		sort(a+1,a+1+n,cmp);
		int sum=0;
		for(int i=1;i<=n/2;i++){
			if(a[i].a1>a[i].a2 && a[i].a1>a[i].a3 && b[i]!=0){
				sum+=a[i].a1;
				s--;
				b[i]=0;
			}
		}
		sort(a+1,a+1+n,cmp2);
		for(int i=1;i<=n/2;i++){
			if(a[i].a2>a[i].a1 && a[i].a2>a[i].a3 && b[i]!=0){
				sum+=a[i].a2;
				s--;
				b[i]=0;
			}
		}
		sort(a+1,a+1+n,cmp3);
		for(int i=1;i<=n/2;i++){
			s--;
			sum+=a[i].a3;
			b[i]=0;
		}
		if(s!=0){
			for(int i=1;i<=n;i++){
				if(b[i]!=0){
					if((a[i].a1>a[i].a2 && a[i].a1<a[i].a3)||(a[i].a1<a[i].a2 && a[i].a1>a[i].a3)){
						sum+=a[i].a1;
					}
					else if((a[i].a2>a[i].a3 && a[i].a2<a[i].a1)||(a[i].a2<a[i].a3 && a[i].a2>a[i].a1)){
						sum+=a[i].a2;
					}else{
						sum+=a[i].a3;
					}
				}
		    }
		}
		cout<<sum<<endl;
	}
	return 0;
} 
