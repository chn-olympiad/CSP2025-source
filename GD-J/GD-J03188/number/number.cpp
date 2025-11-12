#include<iostream>
#include<algorithm>
using namespace std;
string inp,ans;
int a[(int)1e6];
int index;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>inp;
	for(int i=0;i<inp.size();i++){
		if(inp[i]>='0'&&inp[i]<='9'){

			a[index]=inp[i]-'0';
			index++;
		}
	}
	sort(a,a+index);
	for(int i=index-1;i>=0;i--)
		ans+=(a[i]+'0');
	cout<<ans;
	return 0;
} 
