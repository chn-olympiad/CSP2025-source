#include<iostream>
using namespace std;
int n,m,t,a,b,c,a11,a22,a33;
int main(){
	//freopen("club.in ",r,stdin)
	//freopen("club.out",w,stdout)
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a1[10005],a2[10005],a3[10005],ans;
		for(int j=0;j<n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		for(int j=0;j<n;j++){
			if(a1[j]>a2[j] && a1[j]>a3[j]){
			a+=1;
			a11+=a1[j];
		}
			if(a2[j]>a1[j] && a2[j]>a3[j]){
			b+=1;
			a22+=a2[j];;
		}
			if(a3[j]>a1[j] && a3[j]>a2[j]) {
			c+=1;
			a33+=a3[j];
		}
		}
		if(a<=n/2 && b<=n/2 && c<=n/2){
			cout<<a11+a22+a33<<endl;
		}
		
	}
	return 0;
}
