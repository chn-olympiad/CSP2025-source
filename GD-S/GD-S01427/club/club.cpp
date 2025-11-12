#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long n,ans=0;
int a[N][3],b[N][3],bb[N][3],Max[N],m[N],cnt[3];
int t;
bool is2=true,is3=true;
priority_queue<int,vector<int>,greater<int> > pq;
//struct st{
//	int c1,c2,c3;
//	int Max;
//}a[N];

void solve(){
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	memset(Max,0,sizeof(Max));
	memset(m,0,sizeof(m));
	
	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i].c1>>a[i].c2>>a[i].c3;
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(Max[i]<a[i][j]){
				Max[i]=a[i][j];
				m[i]=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cnt[m[i]]++;
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<m[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<3;i++){
//		cout<<cnt[i]<<" ";
//	}
//	cout<<endl;
	
	for(int i=1;i<=n;i++){
		if(a[i][1]>a[i][2]){b[i][0]=a[i][1],bb[i][0]=1;}else{b[i][0]=a[i][2],bb[i][0]=2;}
		if(a[i][0]>a[i][2]){b[i][1]=a[i][0],bb[i][1]=0;}else{b[i][1]=a[i][2],bb[i][1]=2;}
		if(a[i][1]>a[i][0]){b[i][2]=a[i][1],bb[i][2]=1;}else{b[i][2]=a[i][0],bb[i][2]=0;}
//		b[i][0]=max(a[i][1],a[i][2]);
//		b[i][1]=max(a[i][0],a[i][2]);
//		b[i][2]=max(a[i][1],a[i][0]);
	}
	for(int i=0;i<3;i++){
		if(cnt[i]>n/2){
			int x,y,j=1;
			while(m[j]!=i){
				j++;
			}
			x=j;
			j++;
			while(cnt[i]>n/2){
				while(m[j]!=i){
					j++;
				}
				y=j;
//				cout<<x<<" "<<y<<endl;
				if(a[x][i]+b[y][i]>a[y][i]+b[x][i]){
					m[y]=bb[y][i];
//					cout<<"m["<<y<<"]="<<bb[y][i]<<endl;
				}else{
					m[x]=bb[x][i];
//					cout<<"m["<<y<<"]="<<bb[y][i]<<endl;
					x=y;
				}
				cnt[i]--;
				j++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans+=a[i][m[i]];
	}
	cout<<ans<<endl;
	
//	for(int i=1;i<=n;i++){
//		cout<<m[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=0;i<3;i++){
//		cout<<cnt[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<3;j++){
//			cout<<bb[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
}

void solve2(){
	ans=0;
	cnt[0]=cnt[1]=cnt[2]=0;
	memset(Max,0,sizeof(Max));
	memset(m,0,sizeof(m));
	
	bool r[n+1];
	
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			if(Max[i]<a[i][j]){
				Max[i]=a[i][j];
				m[i]=j;
			}
		}
		if(a[i][1]!=0){
			is2=false;
		}
		if(a[i][2]!=0){
			is3=false;
		}
	}
	
	while(!pq.empty()){
		pq.pop();
	}
	if(is2&&is3){
		for(int i=1;i<=n;i++){
			pq.push(Max[i]);
		}
		for(int i=1;i<=n/2;i++){
			ans+=pq.top();
			pq.pop();
		}
		cout<<ans<<endl;
	}else if(is3){
		int mmax=0,mm=0,t1=0,t2=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n;j++){
				if(!r[j]&&mmax<a[0][j]){
					mmax=a[0][j];
					mm=j;
				}
			}
			t1+=mmax;
			r[mm]=true;
		}
		for(int i=1;i<=n;i++){
			if(!r[i]){
				t1+=a[1][i];
			}
		}
		
		memset(r,false,sizeof(r));
		mmax=0,mm=0;
		for(int i=1;i<=n/2;i++){
			for(int j=1;j<=n;j++){
				if(!r[j]&&mmax<a[1][j]){
					mmax=a[1][j];
					mm=j;
				}
			}
			t2+=mmax;
			r[mm]=true;
		}
		for(int i=1;i<=n;i++){
			if(!r[i]){
				t2+=a[0][i];
			}
		}
		cout<<max(t1,t2)<<endl;
	}else{
		solve();
	}
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
//		solve();
		solve2(); 
	}
	return 0;
} 
