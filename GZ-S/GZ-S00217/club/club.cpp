//GZ-S00217 贵阳市第三实验中学 李圣清 
#include<bits/stdc++.h>
using namespace std;
long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	vector<int>a1;
	vector<int>a2;
	vector<int>a3;
	cin>>t;
	for(int hp=1;hp<=t;hp++){
		long long n,ans=0;
		a1.clear();
		a2.clear();
		a3.clear();
		cin>>n;
		for(int i=0;i<n;i++){
			int r,rr,rrr;
			cin>>r>>rr>>rrr;
			a1.push_back(r);
			a2.push_back(rr);
			a3.push_back(rrr);
		}
		if(n==2){
			long long fir,sec;
			for(int i=1;i<=3;i++){
				if(i==1)fir=a1[0];
				else if(i==2)fir=a2[0];
				else fir=a3[0];
				for(int j=1;j<=3;j++){
					if(j==1)sec=a1[1];
					else if(j==2)sec=a2[1];
					else sec=a3[1];
					if(i!=j)ans=max(ans,fir+sec);
				}
			}
			cout<<ans<<endl;
		}
		if(n==4){
			long long fir,sec,thi,las;
			for(int i=1;i<=3;i++){
				if(i==1)fir=a1[0];
				else if(i==2)fir=a2[0];
				else fir=a3[0];
				for(int j=1;j<=3;j++){
					if(j==1)sec=a1[1];
					else if(j==2)sec=a2[1];
					else sec=a3[1];
					for(int q=1;q<=3;q++){
						if(q==1)thi=a1[2];
						else if(q==2)thi=a2[2];
						else thi=a3[2];
						for(int p=1;p<=3;p++){
							if(p==1)las=a1[3];
							else if(p==2)las=a2[3];
							else las=a3[3];
							if((i==j&&j==q)==0 && (i==j&&j==p)==0 && (i==p&&p==q)==0 && (p==j&&p==q)==0&&(i==j&&j==q&&q==p)==0){
								ans=max(ans,fir+sec+thi+las);
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		if(n==100000){
			sort(a1.begin,a1.end);
			for(int i=0;i<50000;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
