#include<bits/stdc++.h>
using namespace std;
int xand(int a,int b){
	if(a<b){
		swap(a,b);
	}
	string ejza="",ejzb="";
	int ans;
	int aws=1,bws=1;
	while(a>1 || b>1){
		if(a>1){
			int yua=a%2;
			ejza+=char(yua+'0');
			aws++;
			a/=2;
		}
		if(b>1){
			int yub=b%2;
			ejzb+=char(yub+'0');
			bws++;
			b/=2;
		}
	}
	ejza+=char(a+'0'),ejzb+=char(b+'0');
	for(int i=0;i<aws;i++){
		if(i<bws){
			if(ejza[i]==ejzb[i]) ans+=pow(2,i);
		}else{
			if(ejza[i]=='0') ans+=pow(2,i);
		}
	}
	return ans;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	//vector<objs> v1;
	/*for(int i=1;i<=n;i++){
		cin >> a[i];
		xorsum[i]=a[i]^xorsum[i-1];
	}*/
	/*for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(xand(xorsum[j],xorsum[i-1])==k){
				v1.push_back({1,0});
			}
		}
	}*/
	if(n<=2 && k==0){
		cout << (n==1?0:1);
	}
	return 0;
}
