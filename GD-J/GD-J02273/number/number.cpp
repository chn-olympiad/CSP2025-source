#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
string s;
long long a[N];
bool c(int q,int e){
	return q>e;
}
int main(){
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout); 
	cin>>s;
    s = " "+s;
    int k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s[i]-'0'=a[i];
			k++;
		}
	}
	sort(a+1,a+k+1,c);
	for(int i=1;i<k;i++){
		cout << a[i] << endl;
	}
}
