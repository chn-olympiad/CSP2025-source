#include<iostream> 
#include<algorithm> 
#include<cstdio> 
#include<cmath>
#include<queue>
using namespace std;
int n,t,ans;
const int N=1e5+86;
struct NNN{
	int value;
	int arr;
	operator >(const NNN& k)const
    { return value>k.value; }
};
int a[N][3],b[3];
int find_up(int i,int f_s_t){
	int x=a[i][0],y=a[i][1],z=a[i][2];
	if(f_s_t==0){
		if(x>=y&&x>=z)return 0;
		if(y>=x&&y>=z)return 1;
		if(z>=x&&z>=y)return 2;
	}
	if(f_s_t==1){
		if(x>=y&&y>=z||z>=y&&y>=x)return 1;
		if(y>=x&&x>=z||z>=x&&x>=y)return 0;
		if(y>=z&&z>=x||x>=z&&z>=y)return 2;
	}
	if(f_s_t==2){
		if(x>=y&&z>=y)return 1;
		if(y>=x&&z>=x)return 0;
		if(x>=z&&y>=z)return 2;
	}
	return 0; 
}
vector<priority_queue<NNN,vector<NNN>,greater<NNN> > >q(3);//Ð¡ÔÚÉÏ 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		scanf("%d",&n);
		b[0]=b[1]=b[2]=0;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
			//cin>>a[i][0]>>a[i][1]>>a[i][2];
			
			int nuum=find_up(i,0);
			NNN nnn={};
			nnn.arr=i;
			nnn.value=a[i][nuum];
			//q[nuum].push(nnn);
			//ans+=nnn.value;
			b[nuum]++;
			if(b[nuum]>n/2){
				NNN kkk=q[nuum].top();
				//q[nuum].pop();
				//ans-=kkk.value;
				int nuuum=find_up(kkk.arr,1);
				
				if(a[i][find_up(i,1)]+kkk.value>nnn.value+a[kkk.arr][nuuum]){  
				 nnn.value=a[i][find_up(i,1)];
				 q[find_up(i,1)].push(nnn);
				 ans+=a[i][find_up(i,1)];
				}else{
					q[nuum].push(nnn);
					ans+=nnn.value;
					q[nuum].pop();
					ans-=kkk.value;
					kkk.value=a[kkk.arr][nuuum];
					ans+=kkk.value;
					b[nuum]--;
					q[nuuum].push(kkk);
					b[nuuum]++;
				}
				//kkk.value=a[kkk.arr][nuuum];
				//ans+=kkk.value;
				//b[nuum]--;
				//q[nuuum].push(kkk);
				//b[nuuum]++;
			}else{
				q[nuum].push(nnn);
				ans+=nnn.value;
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}
/*1
4
0 1 0
0 1 0
0 2 0
0 2 0*/
