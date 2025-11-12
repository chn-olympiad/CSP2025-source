#include<bits/stdc++.h>
using namespace std;
string a[200001],b[200001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=1;i<=x;i++){
		cin>>a[i]>>b[i];
	}
	while(y--){
		string aa,bb;
		int sum=0;
		cin>>aa>>bb; 
		for(int i=1;i<=x;i++){
			int r=aa.find(a[i][0]);
			int len=a[i].size();
			string z=b[i];
			aa.replace(r,len,z);
			if(bb==aa) sum++;
		}
		printf("%d",sum);
	}
	return 0;
}
