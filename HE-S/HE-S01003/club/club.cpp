#include<bits/stdc++.h>
using namespace std;
const int M=100005;

struct S{
	int x,y,z;//zhi,ren,yuan
};
S a[6*M];
bool bo[4*M];

bool cmp(S a,S b){
	return a.x>b.x;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){

		int n;cin>>n;
		for(int i=1;i<=n;i++){
			bo[i]=false;
		}
		int L=n/2;
		int tot=0;
		for(int i=1;i<=n;i++){
			int x,y,z;cin>>x>>y>>z;
			tot++;
			a[tot].x=x;
			a[tot].y=i;
			a[tot].z=1;
			tot++;
			a[tot].x=y;
			a[tot].y=i;
			a[tot].z=2;
			tot++;
			a[tot].x=z;
			a[tot].y=i;
			a[tot].z=3;
			
	    }
	    //cout<<tot<<' ';
	    //for(int i=1;i<=tot;i++)cout<<a[i].x<<a[i].y<<a[i].z<<endl;
	    int l[3];
	    l[1]=0;l[2]=0;l[3]=0;
	    
        sort(a+1,a+tot+1,cmp);
        
        //for(int i=1;i<=tot;i++)cout<<a[i].x<<a[i].y<<a[i].z<<endl;
        
	    long long sum=0;
	    for(int i=1;i<=tot;i++){
	    	int x=a[i].x,y=a[i].y,z=a[i].z;
	    	
	    	//cout<<x<<' '<<y<<' '<<z<<endl;
	    	
	    	if(!bo[a[i].y] && l[a[i].z]<L){
	    		//cout<<9;
	    	    l[a[i].z]++;
	        	bo[a[i].y]=true;
	    	    sum+=a[i].x;
			}
		}
	    
		cout<<sum<<endl;
	}
	return 0;
}
