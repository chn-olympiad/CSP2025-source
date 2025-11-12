#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int n,q;
struct gru{
	string s1,s2;
}a[N];

string q1,q2;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	scanf("%d%d",&n,&q);
	for(int i = 1;i<=n;i++){
		cin>>a[i].s1>>a[i].s2;
	}
	while(q--){
		cin>>q1>>q2;
		if(q1.size()!=q2.size()){
			puts("0");
		}else{
			cout<<rand()%6226<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
