#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string s;
int k=0;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	int lens=s.size();
	for(int i=0;i<lens;i++){
		k++;
		if('0'<=s[i]&&s[i]<='9'){
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+lens+1,cmp);
		for(int i=1;i<=lens;i++){
			cout<<a[i];
		}
		return 0;
}
