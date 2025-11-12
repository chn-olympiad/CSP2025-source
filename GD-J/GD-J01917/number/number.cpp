#include<bits/stdc++.h>
using namespace std;
string k;
int q[1000001];
int j=0;
bool cmp(int x,int y){
	if(x>y) return 1;
	return 0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>k;
	int si=k.size();
	for(int i=0;i<si;i++){
		if(k[i]>='0'&&k[i]<='9'){
			j++;
			q[j]=int(k[i]-'0');
		}
	}
	sort(q+1,q+j+1,cmp);
	for(int o=1;o<=j;o++){
		cout<<q[o];
	}
	return 0;
}
