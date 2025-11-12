#include <bits/stdc++.h>
using namespace std;
int t,n,sum,ak[100010],bk[100010],ck[100010],a,b,c,aak,bbk,cck,aa,bb,cc,aaa[100010],bbb[100010],ccc[100010],minaa,minbb,mincc,mina=99999,minb=99999,minc=99999;
void f1(int x){
	for(int i=1;i<=x;i++){
		if(mina>=ak[i]){
			if(mina==ak[i] && aaa[minaa]<aaa[i]) minaa=i;
			else{
				mina=ak[i];
				minaa=i;
			}
		}
	}
}void f2(int x){
	for(int i=1;i<=x;i++){
		if(minb>=bk[i]){
			if(minb==bk[i] && bbb[minbb]<bbb[i]) minbb=i;
			else{
				minb=bk[i];
				minbb=i;
			}
		}
	}
}
void f3(int x){
	for(int i=1;i<=x;i++){
		if(minc>=ck[i]){
			if(minc==ck[i] && ccc[mincc]<ccc[i]) mincc=i;
			else{
				minc=ck[i];
				mincc=i;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a==b && b==c) sum+=a;
			else if(a==b && a>c) sum+=a;
			else if(a==c && a>b) sum+=a;
			else if(b==c && b>a) sum+=b;
			else if(a>b && a>c){
				aa++;
				aak++;
				if(aa>n/2){
					int j=1;
					while(aaa[j]==0){
						j++;
					}
					sort(aaa+1,aaa+aa+j-1);
					sum+=max(max(a-mina,max(b,c)),a-aaa[j]);
					if(a-aaa[j]>=max(b,c) && a-mina<=a-aaa[j]){
						aaa[j]=0;
						ak[j]=99999;
						aaa[aak]=a-max(b,c);
						ak[aak]=a;
						minaa=0;
						mina=99998;
						f1(aak);
					}
					else if(a-mina>=max(b,c) && a-mina>=a-aaa[j]){
						ak[minaa]=99999;
						aaa[minaa]=0;
						aaa[aak]=a-max(b,c);
						ak[aak]=a;
						minaa=0;
						mina=99998;
						f1(aak);
					}	
					aa--;
				}
				else{
					sum+=a;
					aaa[aa]=a-max(b,c);
					ak[aa]=a;
					if(a<=mina){
						if(a==mina && aaa[aa]>aaa[minaa]) minaa=aa;
						else if(a<mina){
							mina=a;
							minaa=aa;
						}
					}
				}
			}
			else if(b>a && b>c){
				bb++;
				bbk++;
				if(bb>n/2){
					int j=1;
					while(bbb[j]==0){
						j++;
					}
					sort(bbb+1,bbb+j+bb-1);
					sum+=max(max(b-minb,max(a,c)),b-bbb[j]);
					if(b-bbb[j]>=max(a,c) && b-minb<=b-bbb[j]){
						bbb[j]=0;
						bk[j]=99999;
						bbb[bbk]=b-max(a,c);
						bk[bbk]=b;
						minbb=0;
						minb=99998;
						f2(bbk);
					}
					else if(b-minb>=max(a,c) && b-minb>=b-bbb[j]){
						bk[minbb]=99999;
						bbb[minbb]=0;
						bbb[bbk]=b-max(a,c);
						bk[bbk]=b;
						minbb=0;
						minb=99998;
						f2(bbk);
					}	
					bb--;
				}
				else{
					sum+=b;
					bbb[bb]=b-max(a,c);
					bk[bb]=b;
					if(b<=minb){
						if(b==minb && bbb[bb]>bbb[minbb]) minbb=bb;
						else{
							minb=b;
							minbb=bb;
						}
					}
				}
			}
			else if(c>a && c>b){
				cc++;
				cck++;
				if(cc>n/2){
					int j=1;
					while(ccc[j]==0){
						j++;
					}
					sort(ccc+1,ccc+j+cc-1);
					sum+=max(max(c-minc,max(b,a)),c-ccc[j]);
					if(c-ccc[j]>=max(b,a) && c-minc<=c-ccc[j]){
						ccc[j]=0;
						ck[j]=99999;
						ccc[cck]=c-max(a,b);
						ck[cck]=c;
						mincc=0;
						minc=99998;
						f3(cck);
					}
					else if(c-minc>=max(b,a) && c-minc>=c-ccc[j]){
						ck[mincc]=99999;
						ccc[mincc]=0;
						ccc[cck]=c-max(a,b);
						ck[cck]=c;
						mincc=0;
						minc=99998;
						f3(cck);
					}	
					cc--;
				}
				else{
					sum+=c;
					ccc[cc]=c-max(b,a);
					ck[cc]=c;
					if(c<=minc){
						if(c==minc && ccc[cc]>ccc[mincc]) mincc=cc;
						else{
							minc=c;
							mincc=cc;
						}
					}
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
		memset(aaa,0,aak);
		memset(bbb,0,bbk);
		memset(ccc,0,cck);
		memset(ak,0,aak);
		memset(bk,0,bbk);
		memset(ck,0,cck);
		aa=0,bb=0,cc=0,aak=0,bbk=0,cck=0;
		mina=99999,minb=99999,minc=99999;
		minaa=0,minbb=0,mincc=0;
	}
	return 0;
}
