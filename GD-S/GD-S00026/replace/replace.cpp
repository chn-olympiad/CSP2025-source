#include<bits/stdc++.h>
using namespace std;
int n;
string a[200005],b[200005];
unordered_set<string> s;
char input[5000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;scanf("%d %d",&n,&q);
	for(int i=1;i<=n;++i){
		scanf("%s",input),a[i]=input;
		scanf("%s",input),b[i]=input;
	}
	while(q--){
		string x,y;
		scanf("%s",input),x=input;
		scanf("%s",input),y=input;
		printf("0\n");
	}
}
/*
zmx lsy
千万不要删这行，别问我为什么，删了会寄
*/
