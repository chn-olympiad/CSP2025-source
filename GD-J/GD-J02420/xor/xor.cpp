#include<bits/stdc++.h>
using namespace std;
int n,k,cntmax=-1;
int l[500020];
int ccnt;
int c2[50020]={0};
void tt(int x){
	int cnt=1;
	while(x){
		c2[cnt]=x%2;
		x/=2;
		cnt++;
	}
	cntmax=max(cnt-1,cntmax);
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		int c1[50020]={0};
		int _cnt=0;
		for(int j=i;j<=n;j++){
			tt(l[j]);
			for(int k=1;k<=cntmax;k++){
				if(c2[k]==c1[k]){
					c1[k]=0;
				}
				else{
					c1[k]=1;
					_cnt+=pow(2,k-1);
				}
				if(c2[k]==1){
					c2[k]=0;
				}
			}
			if(_cnt==k){
				ccnt++;
				cout<<i<<" "<<j<<endl;
			}
		}
		
	}
	cout<<ccnt;
	return 0;
} 
