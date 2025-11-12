#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string a;
int b[maxn];
int add=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			a[i]=a[i]-'a'+'0'+1;
			b[add]=(int)a[i];
			add++;
		}
	}
	sort(b,b+add);
	for(int i =add-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}
