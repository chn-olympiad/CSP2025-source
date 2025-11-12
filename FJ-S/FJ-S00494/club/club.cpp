#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005][4];
int b[100005][4];
int c[100005],e[100005],r[100005],t[100005],shu[100005];
bool f[100005];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int gg;//t个数据组数
	cin>>gg;
	while(gg--){
		int n;//n个新成员 
		cin>>n;
		int zong=0;//总的满意度 
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];//第i个新成员对第1,2,3个部门的满意度
			if(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3]){
				b[i][2]=a[i][2]-a[i][1];
			}//2 3 1
			else if(a[i][2]>=a[i][1]&&a[i][3]>=a[i][2]){
				b[i][3]=a[i][3]-a[i][2];
			}//1 2 3
			else if(a[i][2]<=a[i][1]&&a[i][3]<=a[i][2]){
				b[i][1]=a[i][1]-a[i][2];
			}//3 2 1
			else if(a[i][1]>=a[i][2]&&a[i][3]>=a[i][1]){
				b[i][3]=a[i][3]-a[i][1];
			}//2 1 3
			else if(a[i][2]>=a[i][3]&&a[i][3]>=a[i][1]){
				b[i][2]=a[i][2]-a[i][3];
			}//1 3 2
			else if(a[i][3]<=a[i][1]&&a[i][3]>=a[i][2]){
				b[i][3]=a[i][3]-a[i][1];
			}//3 1 2
		}
		int p=0,o=0;//分别记录1，2，3最大数的数量 
		int l=0;
		int flag=0;
		for(int i=1;i<=n;i++){
			if(!(a[i][1]==a[i][2]||a[i][2]==a[i][3]||a[i][1]==a[i][3])){
				if(max(max(a[i][3],a[i][2]),a[i][1])==a[i][1]){
					c[i]=1;// 最第i人的 最大数是1
					p++;
					e[p]=i;// 记录最大数是1的第p个人 
				}
				else if(max(max(a[i][3],a[i][2]),a[i][1])==a[i][2]){
					c[i]=2;
					o++;
					r[o]=i;
				}
				else if(max(max(a[i][3],a[i][2]),a[i][1])==a[i][3]){
					c[i]=3;
					l++;
					t[l]=i;
				}
			}
			else{
				flag=1;
			}
			
		}
		if(flag==1){
			for(int i=1;i<=n;i++){
				if(a[i][1]==a[i][2]&&p<=o){
					c[i]=1;
					p++;
					e[p]=i;
				}
				else if(a[i][1]==a[i][2]&&p>o){
					c[i]=2;
					o++;
					r[o]=i;
				}
				else if(a[i][2]==a[i][3]&&o<=l){
					c[i]=2;
					o++;
					r[o]=i;
				}
				else if(a[i][2]==a[i][3]&&o>l){
					c[i]=3;
					l++;
					t[l]=i;
				}
				else if(a[i][1]==a[i][3]&&p>l){
					c[i]=3;
					l++;
					t[l]=i;
				}
				else if(a[i][1]==a[i][2]&&p<=l){
					c[i]=1;
					p++;
					e[p]=i;
				}
				
			}
			
		}
		if(p>n/2){
			int k=p-n/2;
			for(int i=1;i<=p;i++){
				shu[i]=b[e[i]][1]; 
			}
			sort(shu+1,shu+1+p);
			for(int i=p;i>=p-n/2+1;i--){
				zong+=shu[i];
			}
			for(int i=1;i<=n;i++){
				zong+=max(a[i][2],a[i][3]);
			}
		}
		else if(o>n/2){
			int k=o-n/2;//多的人 
			for(int i=1;i<=o;i++){
				shu[i]=b[r[i]][2]; 
			}
			sort(shu+1,shu+1+o);
			for(int i=o;i>=o-n/2+1;i--){
				zong+=shu[i];
			}
			for(int i=1;i<=n;i++){
				zong+=max(a[i][1],a[i][3]);
			}
		}
		else if(l>n/2){
			int k=l-n/2;//多的人 
			for(int i=1;i<=l;i++){
				shu[i]=b[t[i]][3]; 
			}
			sort(shu+1,shu+1+l);
			for(int i=l;i>=l-n/2+1;i--){
				zong+=shu[i];
			}
			for(int i=1;i<=n;i++){
				zong+=max(a[i][2],a[i][1]);
			}
		}
		else{
			for(int i=1;i<=n;i++){
				zong+=max(max(a[i][1],a[i][2]),a[i][3]);
			}
		}
		cout<<zong;
	}
	return 0;
}
