#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int k=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){ 
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	//#Shang4Shan3Ruo6Shui4
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int stlen=s.size();
	for (int i=0;i<stlen;i++){
		if (s[i]>='0'&&s[i]<='9'){
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+1+k,cmp);
	for (int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
}
