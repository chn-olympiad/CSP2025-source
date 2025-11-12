#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500005],vis[500005];
/*线索：*/
/*对于两个互不相等的正整数a b,
  如果两个数都是2^k(k>=0)次方，
  那么其异或运算视作加法。*/
/*a^a=0;
  a^0=a。*/
/*a%2==0:
  a^1=a+1;
  a%2!=0:
  a^1=a-1;(保底有了)
*/
//还是弄一点点分吧
//完成A,B性质
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	if(k==0){//找0
		for(int i=1;i<=n;i++)if(a[i]==0)cnt++,vis[i]=true;
		for(int i=1;i<=n;i++){
			if(a[i]==1 && a[i+1]==1 && !vis[i] && !vis[i+1]){
				cnt++;
				vis[i]=true;
				vis[i+1]=true;
			}	
		}
	}
	else for(int i=1;i<=n;i++)if(a[i]==1)cnt++;
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}