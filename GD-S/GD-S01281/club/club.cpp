#include<bits/stdc++.h>
using namespace std;
int t,n;
int ans1;
int part[100005],second_part[100005];
int m[100005][5],maxn[100005],d[5];

void check(bool p1,bool p2,bool p3){
	if(p1==false && p2==false){
		if(p3==false){
			cout<<ans1<<endl;
			return;
		}
	}
	if(p1==true){
		int minn,tar;
		for(int u=1;u<=d[1]-(n/2);u++){
			minn=30000;
			for(int i=1;i<=n;i++){
			    if(part[i]==1 && minn> (m[i][part[i]]-m[i][second_part[i]]) ){
				    tar=i;
				    minn=(m[i][part[i]]-m[i][second_part[i]]);
			    }
		    }
		    ans1-=(m[tar][part[tar]]-m[tar][second_part[tar]]);
		    part[tar]=4;
		}
	}else if(p2==true){
		int minn,tar;
		for(int u=1;u<=d[2]-(n/2);u++){
			minn=30000;
			for(int i=1;i<=n;i++){
			    if(part[i]==2 && minn> (m[i][part[i]]-m[i][second_part[i]]) ){
				    tar=i;
				    minn=(m[i][part[i]]-m[i][second_part[i]]);
			    }
		    }
		    ans1-=(m[tar][part[tar]]-m[tar][second_part[tar]]);
		    part[tar]=4;
		}
	}else if(p3==true){
		int minn,tar;
		for(int u=1;u<=d[3]-(n/2);u++){
			minn=30000;
			for(int i=1;i<=n;i++){
			    if(part[i]==3 && minn> (m[i][part[i]]-m[i][second_part[i]]) ){
				    tar=i;
				    minn=(m[i][part[i]]-m[i][second_part[i]]);
			    }
		    }
		    ans1-=(m[tar][part[tar]]-m[tar][second_part[tar]]);
		    part[tar]=4;
		}
	}
	cout<<ans1<<endl;
	return;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		d[1]=0;d[2]=0;d[3]=0;
		bool rest[5]={false};
		ans1=0;
		cin>>n;
	    for(int i=1;i<=n;i++){
		    cin>>m[i][1]>>m[i][2]>>m[i][3];
		    maxn[i]=-1;
		    
		    for(int j=1;j<=3;j++){
			    if(maxn[i]<m[i][j]){
				    maxn[i]=m[i][j];
				    part[i]=j;
			    }
		    }
		    ans1+=maxn[i];
		    d[part[i]]++;//求第一位 
		    
			int lll;
		    lll=m[i][part[i]];
		    m[i][part[i]]=-5;
		    maxn[i]=-1;
		    for(int j=1;j<=3;j++){
			    if(maxn[i]<m[i][j]){
				    maxn[i]=m[i][j];
				    second_part[i]=j;
			    }
		    }
		    m[i][part[i]]=lll;//求第二位 
		    
		    if(d[part[i]]>(n/2)) rest[part[i]]=true;
	    }
	    check(rest[1],rest[2],rest[3]);
	}
	return 0;
}
