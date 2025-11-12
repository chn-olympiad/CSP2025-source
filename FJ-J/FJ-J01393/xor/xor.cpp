#include<bits/stdc++.h>
using namespace std;
int n,kkk;
int a[500005];
int b[500005],c[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>kkk;
	bool p=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1) p=0;
	}
	if(p==1){
		int x=0,y=0; 
		for(int i=1;i<=n;i++){
			if(a[i]==0) x++;
			if(a[i]==1) y++;
		} 
		if(kkk>1) cout<<0;
		else if(kkk==1){
			cout<<y;
		}
		else{
			cout<<x+y/2;
		}
		return 0;
	}
	string o="";
	int d=kkk;
	while(d){
		o+=char(d%2+48);
		d/=2;
	}
	int tit=0;
	for(int i=1;i<=n;i++){
		string k="";
		for(int j=i;j<=n;j++){
			int x=a[j];
			string y="";
			while(x){
				y+=char(x%2+48);
				x/=2;
			}
			
			string s="";
			for(int i=y.size()-1;i>=0;i--){
				s+=y[i];
			}
			if(a[j]==0) s='0';
			if(j==i){
				k=s;
				if(y==o){
					tit++;
					b[tit]=i;
					c[tit]=i;
				}
			}	
			else{
				//cout<<s<<" "<<j<<endl;
				int kk=k.size()-1,ss=s.size()-1;
				string h="";
				while(kk>=0&&ss>=0){
					if(k[kk]==s[ss]) h+='0';
					else h+='1';
					kk--;ss--;
					
				}
				if(kk>=0){
					while(kk>=0){
						if(k[kk]=='1') h+='1';
						if(k[kk]=='0') h+='0';
						kk--;
						
					}
				}
				if(ss>=0){
					while(ss>=0){
						if(s[ss]=='1') h+='1';
						if(s[ss]=='0') h+='0';
						ss--;
						
					}
				}
				k=h;
				//cout<<h<<" "<<i<<" "<<j<<endl;
				if(h==o){
					tit++;
					b[tit]=i;
					c[tit]=j;
				}
			}
		}
	}
//	for(int i=1;i<=tit;i++){
//		cout<<b[i]<<" "<<c[i]<<endl;	
//	}
//	cout<<endl;
	int ans=0,sum=0;
	for(int i=1;i<=tit;i++){
		int mn=1e9,mnp=-1;
		for(int j=1;j<=tit;j++){
			//cout<<j<<" "<<c[j]<<" "<<mn<<" "<<b[j]<<" "<<ans<<endl;
			if(c[j]<mn&&b[j]>ans){
				mn=c[j];
				mnp=j;
			}
		}
		//cout<<mn<<" "<<mnp<<endl;
		if(mnp==-1){
			cout<<sum;
			return 0;
		}
		sum++;
		ans=c[mnp];
		
	}
	cout<<sum;
	return 0;
}
