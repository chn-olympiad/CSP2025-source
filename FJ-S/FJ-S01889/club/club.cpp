#include<bits/stdc++.h>
using namespace std;
int t;
long long n,ans,Max_ans;
struct note{
	long long x,y,z;
}a[100005];
bool cmp1(note q,note p){
	if(q.x!=p.x){
		return q.x>p.x;
	}
	if(q.y!=p.y){
		return q.y>p.y;
	}
	return q.z>p.z;
}
bool cmp2(note q,note p){
	if(q.x!=p.x){
		return q.x>p.x;
	}
	if(q.z!=p.z){
		return q.z>p.z;
	}
	return q.y>p.y;
}
bool cmp3(note q,note p){
	if(q.y!=p.y){
		return q.y>p.y;
	}
	if(q.x!=p.x){
		return q.x>p.x;
	}	
	return q.z>p.z;
}
bool cmp4(note q,note p){
	if(q.y!=p.y){
		return q.y>p.y;
	}
	if(q.z!=p.z){
		return q.z>p.z;
	}	
	return q.x>p.x;
}
bool cmp5(note q,note p){
	if(q.z!=p.z){
		return q.z>p.z;
	}
	if(q.x!=p.x){
		return q.x>p.x;
	}	
	return q.y>p.y;
}
bool cmp6(note q,note p){
	if(q.z!=p.z){
		return q.z>p.z;
	}
	if(q.y!=p.y){
		return q.y>p.y;
	}
	return q.x>p.x;
}
int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		Max_ans=0;
		for(int j=1;j<=n;++j){
			cin>>a[j].x>>a[j].y>>a[j].z;
		}
		sort(a+1,a+1+n,cmp1);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		
		
		
		
		
		
		
		
		
		
		sort(a+1,a+1+n,cmp2);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		
		
		
		
		
		
		
		
		
		sort(a+1,a+1+n,cmp3);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		
		
		
		
		
		
		
		
		
		
		sort(a+1,a+1+n,cmp4);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		
		
		
		
		
		
		
		
		
		sort(a+1,a+1+n,cmp5);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		
		
		
		
		
		
		
		
		
		sort(a+1,a+1+n,cmp6);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].x;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].x; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].y;
			}
			else{
				ans+=a[k].z; 
			}
		}
		Max_ans=max(Max_ans,ans);
		ans=0;
		for(int k=1;k<=n;++k){
			if(k<=n/2){
				ans+=a[k].z;
			}
			else{
				ans+=a[k].y; 
			}
		}
		Max_ans=max(Max_ans,ans);
		cout<<Max_ans<<endl;
	}
	
	fclose(stdin);	
	fclose(stdout);
	return 0;
} 
