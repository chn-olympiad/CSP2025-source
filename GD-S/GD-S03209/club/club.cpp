#include<bits/stdc++.h>
using namespace std;
int n,t,a[5],ans=0;
struct myd{
	int m[5],jr,jr2,last;
	int qd;
}cy[100010];
bool cmp(myd a,myd b){
	return a.jr-a.jr2<b.jr-b.jr2;
}
void bh(){
	for(int i=0;i<n;i++){
		if(cy[i].jr==0){
//			if(cy[i].m[1]>=cy[i].m[2]&&cy[i].m[1]>=cy[i].m[2]){
//				cy[i].jr=1;
//				cy[i].qd=cy[i].m[1];
//				if(cy[i].m[2]>=cy[i].m[3])cy[i].jr2=2,cy[i].last=3;
//				else if(cy[i].m[3]>=cy[i].m[2])cy[i].jr2=3,cy[i].last=2;
//				a[1]++;
//			}
//			else if(cy[i].m[2]>=cy[i].m[1]&&cy[i].m[2]>=cy[i].m[3]){
//				cy[i].jr=2;
//				cy[i].qd=cy[i].m[2];
//				if(cy[i].m[1]>=cy[i].m[3])cy[i].jr2=1,cy[i].last=3;
//				else if(cy[i].m[3]>=cy[i].m[1])cy[i].jr2=3,cy[i].last=1;
//				a[2]++;
//			}
//			else if(cy[i].m[3]>=cy[i].m[2]&&cy[i].m[3]>=cy[i].m[1]){
//				cy[i].jr=3;
//				cy[i].qd=cy[i].m[3];
//				if(cy[i].m[2]>=cy[i].m[1])cy[i].jr2=2,cy[i].last=1;
//				else if(cy[i].m[1]>=cy[i].m[2])cy[i].jr2=1,cy[i].last=2;
//				a[3]++;
//			}
			cy[i].jr=1;
			cy[i].jr2=2;
			cy[i].last=3;
		}
	}
	int gb=0;
	while(gb<=4){
		gb++;
		if(a[gb]>n/2){
			break;
		}
	}
	if(1<=gb&&4>gb){
		
		sort(cy,cy+n,cmp);
		if(gb==1){
			int p=0;
			while(a[1]>n/2){
				int abc=cy[p].jr;
				cy[p].jr=cy[p].jr2;
				cy[p].jr2=cy[p].last;
				cy[p].last=abc;
				a[1]--;
				a[cy[p].jr2]++;
				cy[p].qd=cy[p].m[cy[p].jr];
			}
		}	
		if(gb==2){
			int p=0;
			while(a[2]>n/2){
				int abc=cy[p].jr;
				cy[p].jr=cy[p].jr2;
				cy[p].jr2=cy[p].last;
				cy[p].last=abc;
				a[2]--;
				a[cy[p].jr2]++;
				cy[p].qd=cy[p].m[cy[p].jr];
			}
		}	
		if(gb==3){
			int p=0;
			while(a[3]>n/2){
				int abc=cy[p].jr;
				cy[p].jr=cy[p].jr2;
				cy[p].jr2=cy[p].last;
				cy[p].last=abc;
				a[3]--;
				a[cy[p].jr2]++;
				cy[p].qd=cy[p].m[cy[p].jr];
			}
		}	
	}
	

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++){
		ans=0;
		cin>>n;
		for(int i=1;i<=3;i++)a[i]=0;
		for(int i=0;i<n;i++){
			cy[i].last=0;
			cy[i].jr=0;
			cy[i].jr2=0;
			cin>>cy[i].m[1]>>cy[i].m[2]>>cy[i].m[3];
			if(cy[i].m[1]>cy[i].m[2]&&cy[i].m[1]>cy[i].m[2]){
				cy[i].jr=1;
				cy[i].qd=cy[i].m[1];
				if(cy[i].m[2]>=cy[i].m[3])cy[i].jr2=2,cy[i].last=3;
				else if(cy[i].m[3]>cy[i].m[2])cy[i].jr2=3,cy[i].last=2;
				a[1]++;
			}
			else if(cy[i].m[2]>cy[i].m[1]&&cy[i].m[2]>cy[i].m[3]){
				cy[i].jr=2;
				cy[i].qd=cy[i].m[2];
				if(cy[i].m[1]>=cy[i].m[3])cy[i].jr2=1,cy[i].last=3;
				else if(cy[i].m[3]>cy[i].m[1])cy[i].jr2=3,cy[i].last=1;
				a[2]++;
			}
			else if(cy[i].m[3]>cy[i].m[2]&&cy[i].m[3]>cy[i].m[1]){
				cy[i].jr=3;
				cy[i].qd=cy[i].m[3];
				if(cy[i].m[2]>=cy[i].m[1])cy[i].jr2=2,cy[i].last=1;
				else if(cy[i].m[1]>cy[i].m[2])cy[i].jr2=1,cy[i].last=2;
				a[3]++;
			}
		}
			bh();
				for(int i=1;i<=3;i++){
					for(int j=1;j<n;j++){
						ans+=cy[i].qd;
					}
				}
				cout<<ans<<endl;
				continue;
			}
	return 0;
}
