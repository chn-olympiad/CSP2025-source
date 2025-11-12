 #include<bits/stdc++.h>
using namespace std;
string a;
int da,k[1000001],k1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<int(a.size());i++){
		if(int(a[i])>=48&&int(a[i])<=57){
			k[k1]=a[i]-'0';
			k1++;
		}
	}
//	for(int i=0;i<k1;i++){
//		cout<<k[i];
//	}
	sort(k,k+k1);
	for(int i=k1-1;i>=0;i--){
		cout<<k[i];
	}
	return 0;
}