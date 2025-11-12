#include <bits/stdc++.h>
using namespace std;
//int k(int x){
	//for(int i=)
//}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n][3],b[n],c[n],o[3]={0},sum=0;
		for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];
		for(int i=0;i<n;i++){
			b[i]=max(a[i][0],max(a[i][1],a[i][2]));
			sum+=b[i];
			for(int j=0;j<3;j++){
				if(b[i]==a[i][j]){
					o[j]++;
					break;
				} 
			}
			c[i]=b[i]-min(a[i][0],min(a[i][1],a[i][2]));
		}
		sort(b,b+n,cmp);
		int num=max(o[0],max(o[1],o[2])),s;
		if(num>n/2){
			int h=num-n/2;
			sum+=h;
			//sum-=k(h);
			cout<<sum<<endl;
		}
		else cout<<sum<<endl;
	}
} 
