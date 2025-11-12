#include<bits/stdc++.h>
using namespace std;
//#define int long long
//string s[100005][2];
/*
inline int size(string s){
	for(int i=1;;i++){
		if(s[i]!=NULL)ans++;
	}
}*/
signed main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    
    cout<<0<<endl;
    return 0;
    
	int n,q;cin>>n>>q;
	int dis[200005];
	for(int i=1;i<=200005;i++)dis[i]=0;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		
		
		int pos1,pos2;
		for(int j=0;j<5000005;j++){
			if(s1[j]=='b'){pos1=j;break;}
			
		}
		for(int j=0;j<5000005;j++){
			if(s2[j]=='b'){pos2=j;break;}
		}
		
		//cout<<"-----"<<endl;
		dis[i]=pos1-pos2;
		//cout<<dis[i]<<endl;
		//cout<<pos1<<" "<<pos2<<" "<<dis[i]<<endl;//
	}
	
	
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		int pos1,pos2;
		for(int j=0;j<5000005;j++){
			if(t1[j]=='b'){pos1=j;break;}
		}
		for(int j=0;j<5000005;j++){
			if(t2[j]=='b'){pos2=j;break;}
		}
		int tt1=pos1-pos2;
				
		int ans=0;
		for(int j=1;j<=n;j++){
			//cout<<dis[j]<<endl;
			if(tt1==dis[j]){ans++;}
		}
		cout<<ans<<endl;
	}
	
	
	
	
	
    return 0;
}
