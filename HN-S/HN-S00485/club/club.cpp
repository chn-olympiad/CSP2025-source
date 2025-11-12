#include<bits/stdc++.h>
using namespace std;
struct idgood{
	int a1;
	int a2;
	int a3;
	int mx;
	int ci;
	int cha;
	int his;
}id[100010];
int cmp(idgood a,idgood b){
	if(a.cha==b.cha){
		return a.mx>b.mx;
	}else{
		return a.cha>b.cha;
	}

}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	int t;
	cin>>t;
	for(int xuhuan=1;xuhuan<=t;xuhuan++){
		int n,f,num=0;
		cin>>n;
		f=n/2;
		for(int i=1;i<=n;i++){
			cin>>id[i].a1>>id[i].a2>>id[i].a3;
			if(id[i].a1>=id[i].a2&&id[i].a1>=id[i].a3){
				id[i].mx=id[i].a1;
				id[i].his=1;
				if(id[i].a2>=id[i].a3){
					id[i].ci=id[i].a2;
				}else{
					id[i].ci=id[i].a3;
				}
			}else{
				if(id[i].a2>=id[i].a1&&id[i].a2>=id[i].a3){
					id[i].mx=id[i].a2;
					id[i].his=2;
					if(id[i].a1>=id[i].a3){
						id[i].ci=id[i].a1;
					}else{
						id[i].ci=id[i].a3;
					}
				}else{
					if(id[i].a3>=id[i].a1&&id[i].a3>=id[i].a2){
						id[i].mx=id[i].a3;
						id[i].his=3;
						if(id[i].a1>=id[i].a2){
							id[i].ci=id[i].a1;
						}else{
							id[i].ci=id[i].a2;
						}
					}
				}
			}
			
			int mi;
			mi=min(id[i].a1,id[i].a2);
			mi=min(id[i].a3,mi);
			id[i].cha=id[i].mx-mi;
		}
		sort(id+1,id+n+1,cmp);
		
		int chao1=0,chao2=0,chao3=0;
		for(int i=0;i<=n;i++){
			if(id[i].his==1){
				
				if(chao1+1<=f){
					chao1++;
					num+=id[i].mx;
					
				}else{
					num+=id[i].ci;
				}
			}else{
				if(id[i].his==2){
					if(chao2+1<=f){
						chao2++;
						num+=id[i].mx;
					}else{
						num+=id[i].ci;
					}
				}else{
					if(id[i].his==3){
						if(chao3+1<=f){
							chao3++;
							num+=id[i].mx;
						}else{
							num+=id[i].ci;
						}
					}
				}
			}
		}
			
			
		cout<<num<<endl;
	}
	
	
	
	
	//Ren5Jie4Di4Ling5%
	return 0;
}
