#include<bits/stdc++.h>
using namespace std;
long long a[10005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long c=0,d=0,b=s.size(),max=0;
	if(s.size()==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<b;i++){
		d=s[i];
		cout<<d<<" ";
		if(49<=d&&d<=57){
			a[c]=d-48;
			c++;
		}
	}
	cout<<endl;
	if(c==1){
		cout<<a[c];
		return 0;
	}
	for(int i=0;i<c;i++){
		for(int i=1;i<c;i++){
			if(a[i]>a[max]){
				max=i;
			}
		}
		cout<<a[max];
		a[max]=0;
		max=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
