 #include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000],b[1000000];
int n = 0;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n] = s[i] - '0';
			n++;
		} 
	}
	int w = n-1;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		b[w] = a[i];
		w--;
	}
	for(int i=0;i<n;i++) cout<<b[i];
	return 0;
}
