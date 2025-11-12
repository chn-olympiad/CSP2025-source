#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][3],p,wa[100010],wap[100010],wao,wb[100010],wbp[100010],wbl,wc[100010],wcp[100010],wcl,tmp[100010],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=wao=p=wbl=wcl=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
			p=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=p;
			for(int j=0;j<3;j++){
				if(p==a[i][j]){
					if(j==0){
						wa[wao]=a[i][0];
						wap[wao]=i;
						wao++;
					}else if(j==1){
						wb[wbl]=a[i][1];
						wbp[wbl]=i;
						wbl++;
					}else if(j==2){
						wc[wcl]=a[i][2];
						wcp[wcl]=i;
						wcl++;
					}
					break;
				}
			}
		}
		if(wao>n/2){
			for(int i=0;i<wao;i++){
				tmp[i]=wa[i]-max(a[wap[i]][1],a[wap[i]][2]);
			}
			sort(tmp,tmp+wao);
			int ch=wao-n/2;
			while(ch>=1){
				ans-=tmp[ch-1];
				ch--;
			}
		}else if(wbl>n/2){
			for(int i=0;i<wbl;i++){
				tmp[i]=wb[i]-max(a[wbp[i]][0],a[wbp[i]][2]);
			}
			sort(tmp,tmp+wbl);
			int ch=wbl-n/2;
			while(ch>=1){
				ans-=tmp[ch-1];
				ch--;
			}
		}else if(wcl>n/2){
			for(int i=0;i<wcl;i++){
				tmp[i]=wc[i]-max(a[wcp[i]][1],a[wcp[i]][0]);
			}
			sort(tmp,tmp+wcl);
			int ch=wcl-n/2;
			while(ch>=1){
				ans-=tmp[ch-1];
				ch--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//Ren5Jie4Di4Ling5%

//Ugh,what a T1!
//I had spent 30mins.
//But only a 'int'!

//I had better go for a picnic.

//1.5 hours later
//I finished it at 16:34!
