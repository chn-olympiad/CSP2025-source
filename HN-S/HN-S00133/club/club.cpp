#include <bits/stdc++.h>
using namespace std;
int b;
int a[3];
struct abc{
	int dy;
	int dr;  
	int ds;
	int zds;
	int zdsbh;
};
bool cmp(abc a,abc b){
	return a.zds>b.zds;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>b;
	for(int i=1;i<=b;i++){
		int a[3]={0,0,0};
		int n;
		cin>>n;
		abc mycd[n];
		int zdzs=0;
		for(int j=0;j<n;j++){
			mycd[j].zds=0;
			cin>>mycd[j].dy;
			if(mycd[j].zds<mycd[j].dy){mycd[j].zds=mycd[j].dy;mycd[j].zdsbh=1;
			}
			cin>>mycd[j].dr; 
			if(mycd[j].zds<mycd[j].dr){mycd[j].zds=mycd[j].dr;mycd[j].zdsbh=2;
			}
			cin>>mycd[j].ds;
			if(mycd[j].zds<mycd[j].ds){mycd[j].zds=mycd[j].ds;mycd[j].zdsbh=3;
			}
		}
	sort(mycd,mycd+n,cmp);
	for(int k=0;k<n;k++){
		a[mycd[k].zdsbh]++;
			if(a[mycd[k].zdsbh]>n/2){a[mycd[k].zdsbh]--;mycd[k].zdsbh++;
			if(mycd[k].zdsbh>3){mycd[k].zdsbh=1;a[mycd[k].zdsbh]++;
			}
			else{a[mycd[k].zdsbh]++;
			}
			}
			if(mycd[k].zdsbh==1){zdzs+=mycd[k].dy;
			}
			else if(mycd[k].zdsbh==2){zdzs+=mycd[k].dr;
			}
			else if(mycd[k].zdsbh==3){zdzs+=mycd[k].ds;
			}
		}
		cout<<zdzs<<endl;
	}
	return 0;
}
			

