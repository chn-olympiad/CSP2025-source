#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
struct node{
	int a[4];
}s[N],s1[N],s2[N],s3[N];
bool cmp1(node x,node y){
	return x.a[1]>=y.a[1];
}
bool cmp2(node x,node y){
	return  x.a[2]>=y.a[2];
}
bool cmp3(node x,node y){
	return  x.a[3]>=y.a[3];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	const char endl='\n';
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>s[i].a[1]>>s[i].a[2]>>s[i].a[3];
		}
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;++i){
			s1[i].a[1]=s2[i].a[1]=s3[i].a[1]=s[i].a[1];
			s1[i].a[2]=s2[i].a[2]=s3[i].a[2]=s[i].a[2];
			s1[i].a[3]=s2[i].a[3]=s3[i].a[3]=s[i].a[3];
		}
		sort(s1+1,s1+n+1,cmp1);
		sort(s2+1,s2+n+1,cmp2);
		sort(s3+1,s3+n+1,cmp3); 
		for(int i=1;i<=n/2;++i){
			c1+=s1[i].a[1];
			c2+=s2[i].a[2];
			c3+=s3[i].a[3];
		}
		for(int i=n/2+1;i<=n;++i){
			c1+=max(s1[i].a[2],s1[i].a[3]);
			c2+=max(s2[i].a[1],s2[i].a[3]);
			c3+=max(s3[i].a[1],s3[i].a[2]);
		}cout<<max(c1,max(c2,c3))<<endl; 
	}
	return 0;
} 
/*3 
4 
4  2  1 
3  2  4  
5  3  4  
3  5  1 
4 
0  1  0 
0  1  0 
0  2  0 
0  2  0 
2 
10  9  8 
4  0  0 

1
10 
2020  14533  18961 
2423  15344   16322 
1910  6224  16178
2038  9963  19722
8375  10557  5444 
3518  14615  17976 
6188  13424  16615 
8769  509  4394 
958  3195  9953 
16441 5313  10926 
147325
*/
