//number
#include<bits/stdc++.h>
using namespace std;
string s;
int maxx,a[1000001],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=(s[i]-'0');
			k++;
		}
	}
	sort(a,a+k);
//	while(a.size()>0){
//		for(int i=0;i<a.size();i++){
//			for(int j=0;j<a.size();j++){
//				maxx=max(maxx,a[j]);
//			}
//			a.erase(begin+i,1);
//			b.pushback(maxx);
//		}
//	}
	for(int i=k-1;i>=0;i--){
		printf("%d",a[i]);
	}
	return 0; 
}
