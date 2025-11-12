
#include <bits/stdc++.h>
using namespace std;
char c[1000012];
priority_queue<int> pq;
int main(){
   freopen("number.in","r",stdin);
   freopen("number.out","w",stdout);
   scanf("%s",c);
   int len=strlen(c);
   int t;
   for(int i=0;i<len;i++){
	   if(c[i]>='0' && c[i]<='9'){
		   t=c[i]-'0';
		   pq.push(t);
	   }
   }
   if(pq.top()==0){
	   printf("0");
	   return 0;
   }
   int tt;
   while(!pq.empty()){
	   tt=pq.top();
	   printf("%d",tt);
	   pq.pop();
   }
	return 0;
}
