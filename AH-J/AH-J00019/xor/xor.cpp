#include<bits/stdc++.h>
using namespace std;
int a[200001];
struct stu{
	int l,r;
}s[200001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ss=0,cnt=0;
	for(int i=0;i<n;i++){
		ss=a[i];
		if(ss==k){
			s[cnt].l=s[cnt].r=i;
			cnt++;
		}else{
			for(int j=i+1;j<n;j++){
				ss^=a[j];
				if(ss==k){
					s[cnt].l=i;
					s[cnt].r=j;
					cnt++;
					break;
				}
			}
		}
	}
	int ar=s[0].r,mg=1;
	for(int i=1;i<cnt;i++){
		if(ar<s[i].l){
			mg++;
			ar=s[i].r;
		}else if(s[i].r<=ar){
			ar=s[i].r;
		}
	}
	cout<<mg;
	return 0;
}
