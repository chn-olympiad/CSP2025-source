#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
vector<int>a,li1,li2;
int xorsum(vector<int>v){
	int sum=v[1];
	for(int i=1;i<v.size();i++){
		sum^=v[i];
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int l1=0,r1=0,l2=n,r2=n,x,sum1=0,sum2=0;
	for(int i=0;i<n;i++)cin>>x,a.push_back(x);
	while(l1!=l2){	
		while(r1!=r2){
		for(int i=l1;i<=r1;i++)li1.push_back(a[i]);
		for(int i=l2;i>=r2;i--)li2.push_back(a[i]);
		if(xorsum(li1)==k&&xorsum(li2)==k)cnt++;
		r1++;
		r2--;
		}
		l1++;
		l2++;
		r2=l2;
		r1=l1;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}