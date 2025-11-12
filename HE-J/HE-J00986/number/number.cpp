#include <bits/stdc++.h>
using namespace std;
string s;
vector <int>b;
int a[1000005];
int num=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//ios::sync_with_stdio(false);
	cin>>s;
	if (s.length()==1){
		cout<<s<<endl;
		return 0;
	}
	for (int i=s.length();i>=0;i--){
		if (int(s[i])>=48 && int(s[i])<=57){
			num++;
			a[num]=int(s[i])-48;
		}
	}
	//cout<<num<<endl;
	for (int i=1;i<=num;i++){
		int tos=0;
		//cout<<a[i]<<" ";
		for (int j=i;j<=num;j++){
			if (a[j] >= a[i]) {
				tos=a[i];
				a[i]=a[j];
				a[j]=tos;//jiao huan
			}
		}
		cout<<a[i];
	}
	return 0;
}
