#include<bits/stdc++.h>
using namespace std;
struct node{
	int l,r,g;
}sss[200001];
int head;
int n,k;
int p;
int sheng;
int tag[200001];
int num=0;
int a[200001];
int s[200001];
bool cmp(node x,node y){
	return x.g<y.g;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>p;
		s[i]=s[i-1]^p;
		for(int j=1;j<=i;j++){
			int q=s[i]^s[j-1];
			if(q==k){
				head++;
				sss[head].r=i;
				sss[head].l=j;
				sss[head].g=i-j+1;
			}
		}
	}
	sort(sss+1,sss+1+head,cmp);
	//for(int i=1;i<=head;i++){
		//cout<<sss[i].l<<" "<<sss[i].r<<endl;
	//}
	for(int i=1;i<=head;i++){
		int z=0;
		if((n-sheng)<sss[i].g){
			break;
		}
		for(int j=sss[i].l;j<=sss[i].r;j++){
			if(tag[j]==1){
				z++;
				break;
			}
		}
		if(z){
			continue;
		}
		for(int j=sss[i].l;j<=sss[i].r;j++){
			tag[j]=1;
			sheng++;
		}
		num++;
	}
	cout<<num;
	return 0;
}
