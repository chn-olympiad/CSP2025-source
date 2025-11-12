#include<bits/stdc++.h>
using namespace std;
string a,c=" ";int b[1000010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;c+=a;int n=c.size();
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n;i++){
		if(c[i]>='0'&&c[i]<='9'){
			b[i]=c[i]-'0';
		}
	}
	sort(b+1,b+n+1,cmp);int j=1;
	while(1){
		if(b[j]==-1)b[j]=-2;
		else if(b[j]!=-1)break;
		j++;
	}
//	for(int i=1;i<=n;i++){
//		cout<<b[i]<<'\n';
//	}
	int i=1;
	while(1){
		if(b[i]==-1)break;
		if(b[i]==-2){
			i++;continue;
		}cout<<b[i];
		i++;
	}
	return 0;
} 
