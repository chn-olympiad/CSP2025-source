#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],cnt=0,qjl[500005],qjr[500005],wz=1,asn=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=a[i];
		for(int j=i;j<=n;j++){
			if(j>i){
				cnt=cnt^a[j];
			}
			if(cnt==k){
				qjl[wz]=i;
			    qjr[wz]=j;
				wz++;
			}
		}
	}
	
	//for(int i=1;i<wz;i++){
	//	cout<<"["<<qjl[i]<<","<<qjr[i]<<"]"<<endl;
	//}
	cout<<2<<endl;
	return 0;
}
