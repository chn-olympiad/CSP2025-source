#include<bits/stdc++.h>

using namespace std;

const int N=1e5+20;

priority_queue<pair<int,int> >q[3][3];//丢i拿j 

int a[3][N],n;
int ch[N];
int s[3],ans=0;

void one(){
	for(int l1=0;l1<=2;l1++){
		for(int l2=0;l2<=2;l2++){
			while(!q[l1][l2].empty())q[l1][l2].pop();
		}
	}
	memset(a,0,sizeof(a));
	ans=s[0]=s[1]=s[2]=0;
	scanf("%d",&n);
	n=1e5;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
	}
	for(int i=1;i<=n;i++){
		int mx=0,q1=0,q2=-1,q3=-1,res=0;
		for(int l1=0;l1<=2;l1++){
			if(s[l1]>=n/2)continue;
			res=a[l1][i];
//			cout<<"<"<<l1<<" "<<res<<"->\n";
			if(res>mx)q1=l1,mx=res;
		}
		if(s[0]>=n/2||s[1]>=n/2||s[2]>=n/2)
		for(int l1=0;l1<=2;l1++){//当前选l1 
			for(int l2=0;l2<=2;l2++){//放弃选l2的 
				for(int l3=0;l3<=2;l3++){//改为选l3的 
					res=0;
					s[l1]++,s[l2]--,s[l3]++;
					if(s[l1]>n/2||s[l2]>n/2||s[l3]>n/2){
						s[l1]--,s[l2]++,s[l3]--;
						continue;
					}
					while(1){
						if(q[l2][l3].empty())break;
						if(ch[q[l2][l3].top().second]!=l2){
							q[l2][l3].pop();
						}else{
							break;
						}
					}
					if(q[l2][l3].empty()){
						s[l1]--,s[l2]++,s[l3]--;
						continue;
					}
					res+=a[l1][i]+q[l2][l3].top().first;
					if(res>mx)q1=l1,q2=l2,q3=l3,mx=res;
					s[l1]--,s[l2]++,s[l3]--;
				}
			}	
		}
		if(q3==-1){
			for(int l1=0;l1<=2;l1++){
				if(l1==q1)continue;
				q[q1][l1].push({a[l1][i]-a[q1][i],i});
			}
			ch[i]=q1;
			s[q1]++;
		}else{
			for(int l1=0;l1<=2;l1++){
				if(l1==q1)continue;
				q[q1][l1].push({a[l1][i]-a[q1][i],i});
			}
			ch[i]=q1;
			int ct=q[q2][q3].top().second;
			ch[ct]=q3;
			q[q2][q3].pop();
			
			for(int l1=0;l1<=2;l1++){
				if(l1==q3)continue;
				q[q3][l1].push({a[l1][i]-a[q3][i],i});
			}
			s[q1]++,s[q2]--,s[q3]++;
		}
//		cout<<":"<<mx<<" "<<q1<<" "<<q2<<" "<<q3<<"\n";
		ans+=mx;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)one();
	return 0;
} 
