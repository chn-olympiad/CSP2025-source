#include<bits/stdc++.h>
using namespace std;
const int maxx=1e+7;
string l;
int n[maxx],le,k;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	cin>>l;
	le=l.length();
	for(int i=0;i<=le;i++){
		if(l[i]=='0'||l[i]=='1'||l[i]=='2'||l[i]=='3'||l[i]=='4'||l[i]=='5'||l[i]=='6'||l[i]=='7'||l[i]=='8'||l[i]=='9'){
			n[k]=int(l[i]-'0');
			k++;
		}
	}
	sort(n,n+k+1);
	for(int i=k;i>0;i--)cout<<n[i];
	return 0;
}
