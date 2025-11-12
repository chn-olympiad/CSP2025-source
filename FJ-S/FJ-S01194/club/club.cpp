#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
int T,t1[N],t2[N],t3[N];
priority_queue<int> q1,q2,q3;
int maxx(int a,int b,int c){
	return max(max(a,b),c);
}
struct node{
	int id,sum,num1,num2,num3,k;
}Node[N];
bool cmp(node a,node b){
	return a.sum>b.sum;
}
bool cmp1(node a,node b){
	return a.num1>b.num1;
}
bool cmp2(node a,node b){
	return a.num2>b.num2;
}
bool cmp3(node a,node b){
	return a.num3>b.num3;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;cin>>n;
		int k=n/2,x1=n/2,x2=n/2,x3=n/2,ans=0,ans1=0,ans2=0,ans3=0,max1=-1,max2=-1,max3=-1,flag=0;
		for(int i=1;i<=n;i++){
			cin>>Node[i].num1>>Node[i].num2>>Node[i].num3;
			Node[i].sum=maxx(Node[i].num1,Node[i].num2,Node[i].num3);
			max1=max(max1,Node[i].num1),max2=max(max2,Node[i].num2),max3=max(max3,Node[i].num3);
			if(maxx(Node[i].num1,Node[i].num2,Node[i].num3)==Node[i].num1)Node[i].k=1;
			else if(maxx(Node[i].num1,Node[i].num2,Node[i].num3)==Node[i].num2)Node[i].k=2;
			else if(maxx(Node[i].num1,Node[i].num2,Node[i].num3)==Node[i].num3)Node[i].k=3;
			Node[i].id=i;
		}
		sort(Node+1,Node+n+1,cmp1);
		for(int i=1;i<=k;i++){
			ans1+=Node[i].num1;
		}
		for(int i=k+1;i<=n;i++){
			ans1+=max(Node[i].num2,Node[i].num3);
		}//1
		sort(Node+1,Node+n+1,cmp2);
		for(int i=1;i<=k;i++){
			ans2+=Node[i].num2;
		}
		for(int i=k+1;i<=n;i++){
			ans2+=max(Node[i].num1,Node[i].num3);
		}//2
		sort(Node+1,Node+n+1,cmp3);
		for(int i=1;i<=k;i++){
			ans3+=Node[i].num3;
		}
		for(int i=k+1;i<=n;i++){
			ans3+=max(Node[i].num2,Node[i].num1);
		}//3
		int anss=maxx(ans1,ans2,ans3);
		sort(Node+1,Node+n+1,cmp);
			for(int i=1;i<=n;i++){
				if(Node[i].k==1){
					if(x1==0){
						ans+=max(Node[i].num2,Node[i].num3);
						if(Node[i].num2>Node[i].num3)x2--;
						else x3--;
					}
					else x1--,ans+=Node[i].sum;
				}
				else if(Node[i].k==2){
					if(x2==0){
						ans+=max(Node[i].num1,Node[i].num3);
						if(Node[i].num1>Node[i].num3)x1--;
						else x3--;
					}
					else x2--,ans+=Node[i].sum;
				}
				else {
					if(x3==0){
						ans+=max(Node[i].num1,Node[i].num2);
						if(Node[i].num1>Node[i].num2)x1--;
						else x2--;
					}
					else x3--,ans+=Node[i].sum;
				}
			}
		cout<<max(ans,anss)<<endl;
		for(int i=1;i<=n;i++){
			Node[i].id=0,Node[i].k=0,Node[i].num1=0,Node[i].num2=0,Node[i].sum=0,Node[i].num3=0;
		}
	}
	return 0;
}
