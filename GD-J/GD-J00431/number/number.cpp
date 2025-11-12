#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string n;
char m[N],x;
int main(){
	freuse("number.in","r",stdin);
	freuse("number.out","w",stdin);
	cin>>n;
	int k=1;
	for(int i=0;i<n.size();i++){
		if(n[i]>='0'&&n[i]<='9'){
			m[k]=n[i];
			k++;
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			if(m[j]<=m[i]){
				x=m[j];
				m[j]=m[i];
				m[i]=x;
			}
		}
	}
	for(int i=1;i<=k;i++){
		cout<<m[i];
	}
	fclose("number.in",stdout);
	fclose("number.out",stdout);
	return 0;
}
