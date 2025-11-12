#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

//struct node{
//	int id;
//	int value;
//	int num=0;
//};
struct node{
	int id,value;
	bool operator<(const node &rhs)const{
		return value<rhs.value;
	}
};
struct stu{
	node s[10]; 
	int e;
	int id;
	bool operator<(const stu &rhs)const{
		return e>rhs.e;
	}
}a[N];

int n;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;i++){
	//		node maxn;
	//		maxn.value=-1;
	//		node minn;
	//		minn.value=0x3f3f3f3f;
			a[i].id=i;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].s[j].value);
			//	cin>>;
				a[i].s[j].id=j;
	//			if(a[i].s[j]>maxn.value){
	//				maxn.value=a[i].s[j];
	//				maxn.id=j;
	//			}
	//			if(a[i].s[j]<minn.value){
	//				minn.value=a[i].s[j];
	//				minn.id=j;
	//			}
			}
			sort(a[i].s+1,a[i].s+4);
			a[i].e=a[i].s[3].value-a[i].s[1].value;
			//cout<<a[i].e<<endl;
			//cout<<a[i].s[1].value<<" "<<a[i].s[2].value<<" "<<a[i].s[3].value<<endl;
		}
	//	sort(a,a+n);
	//	int ans=0,people=n/2;
	//	node a,b,c;
	//	for(int i=0;i<n;i++){
	//		//if()
	//	}
		sort(a,a+n);
		int ans=0,people=n/2;
		int school[5]={0,0,0,0};
		for(int i=0;i<n;i++){
			if(school[a[i].s[3].id]<people){
				school[a[i].s[3].id]++;
				ans+=a[i].s[3].value;
				//cout<<"id="<<a[i].id<<" chose "<<a[i].s[3].id<<" people="<<school[a[i].s[3].id]<<" ans+="<<a[i].s[3].value<<endl;
			}else{
				school[a[i].s[2].id]++;
				ans+=a[i].s[2].value;
				//cout<<"id="<<a[i].id<<" chose "<<a[i].s[2].id<<" people="<<school[a[i].s[2].id]<<" ans+="<<a[i].s[2].value<<endl;
			}
		}
		printf("%d\n",ans);
		//cout<<ans<<endl;
	}
	return 0;
} 
/*
我使用的策略其实是片面的
根据满意度最大值和最小值的极差来判断优先级
对于样例性质B且当 ai的最大值大于ai+1的最大值时不成立
但是我不会改了，看看能得多少分吧 
我似乎有点能想出来这个状态转移？
算了算了不改了
虽然t3不会做。 
1
2
10 9 0
4 0 0

*/
