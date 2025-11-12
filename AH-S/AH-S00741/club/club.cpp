#include<bits/stdc++.h>
using namespace std;
bool cmp(int e,int f){
	return e>f;
}
int a[100010][10],t;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		
		if(n==2){
			for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
			int jd1,jd2,jd3;
			jd1=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			jd2=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			jd3=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			cout<<max(max(jd1,jd2),jd3);
		}
		else{
			if(n==4){
				for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
				int o1,o2,o3,ert=0;
				for(int i=1;i<=3;i++){
					if(i==1) o1++;
					if(i==2) o2++;
					if(i==3) o3++;
					for(int j=1;j<=3;j++){
						if(j==1) o1++;
						if(j==2) o2++;
						if(j==3) o3++;
						for(int k=1;k<=3;k++){
							if(o1==2&&k==1) k++,o2++;
							if(o2==2&&k==2) k++,o3++;
							if(o3==2&&k==3) break;
							
							for(int l=1;l<=3;l++){
								if(o1==2&&l==1) l++;
								if(o2==2&&l==2) l++;
								if(o3==2&&l==3) break;
								ert=max(ert,a[1][i]+a[2][j]+a[3][k]+a[4][l]);
							}
							if(k==1) o1--;
							if(k==2) o2--;
							if(k==3) o3--;
						}
						if(j==1) o1--;
						if(j==2) o2--;
						if(j==3) o3--;
					}
					if(i==1) o1--;
					if(i==2) o2--;
					if(i==3) o3--;
				}
				cout<<ert<<endl;
			}
			else{if(n==10){
				for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
				int o1,o2,o3,ert=0;
				for(int i=1;i<=3;i++){
					if(i==1) o1++;
					if(i==2) o2++;
					if(i==3) o3++;
					for(int j=1;j<=3;j++){
						if(j==1) o1++;
						if(j==2) o2++;
						if(j==3) o3++;
							for(int k=1;k<=3;k++){
								if(k==1) o1++;
								if(k==2) o2++;
								if(k==3) o3++;
								for(int i4=1;i4<=3;i4++){
									if(i4==1) o1++;
									if(i4==2) o2++;
									if(i4==3) o3++;
									for(int i5=1;i5<=3;i5++){
										if(i4==1) o1++;
										if(i4==2) o2++;
										if(i4==3) o3++;
										for(int i6=1;i6<=3;i6++){
											if(o1==5&&i6==1) i6++,o2++;
											if(o2==5&&i6==2) i6++,o3++;
											if(o3==5&&i6==3) break;
											for(int i7=1;i7<=3;i7++){
												if(o1==5&&i7==1) i7++,o2++;
												if(o2==5&&i7==2) i7++,o3++;
												if(o3==5&&i7==3) break;
												for(int i8=1;i8<=3;i8++){
												    if(o1==5&&i8==1) i8++,o2++;
												    if(o2==5&&i8==2) i8++,o3++;
												    if(o3==5&&i8==3) break;
													for(int i9=1;i9<=3;i9++){
														if(o1==5&&i9==1) i9++,o2++;
														if(o2==5&&i9==2) i9++,o3++;
														if(o3==5&&i9==3) break;
														for(int l=1;l<=3;l++){
															if(o1==5&&l==1) l++;
															if(o2==5&&l==2) l++;
															if(o3==5&&l==3) break;
															ert=max(ert,a[1][i]+a[2][j]+a[3][k]+a[4][i4]+a[5][i5]+a[6][i6]+a[7][i7]+a[8][i8]+a[9][i9]+a[10][l]);
														}
														
												if(i9==1) o1--;
												if(i9==2) o2--;
												if(i9==3) o3--;
													}
												if(i8==1) o1--;
												if(i8==2) o2--;
												if(i8==3) o3--;
											}
											if(i7==1) o1--;
											if(i7==2) o2--;
											if(i7==3) o3--;
										}
										if(i6==1) o1--;
										if(i6==2) o2--;
							            if(i6==3) o3--;
									}
									if(i5==1) o1--;
									if(i5==2) o2--;
									if(i5==3) o3--;
								}
								if(i4==1) o1--;
								if(i4==2) o2--;
								if(i4==3) o3--;
							}
							if(k==1) o1--;
							if(k==2) o2--;
							if(k==3) o3--;
						}
						if(j==1) o1--;
						if(j==2) o2--;
						if(j==3) o3--;
					}       	
					if(i==1) o1--;
					if(i==2) o2--;
					if(i==3) o3--;
				}           	
				cout<<ert<<endl;     	
		}                   	
			else{
				int x=0,y=0,z=0,x1=0,y1=0,z1=0,q=1,u=2,o=3;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0||a[i][3]!=0) q=0;
			if(a[i][1]!=0||a[i][3]!=0) u=0;
			if(a[i][2]!=0||a[i][1]!=0) o=0;
			if(max(a[i][1],a[i][2])<a[i][3]&&z1<n/2){
				z+=a[i][3]; 	
				z1++;       	
				a[i][4]=3;  	
			}
			else{ if(a[i][1]<a[i][2]&&y1<n/2){
					y+=a[i][2];
					y1++;
					a[i][4]=2;
				}
				else{
					if(x1<n/2){
						x+=a[i][1];
						x1++;
						a[i][4]=1;
					}
					else{ 
						if(a[i][2]>a[i][3]&&y1<n/2){
							y+=a[i][2];
							y1++;
							a[i][4]=2;
						}
						else{
							z+=a[i][3];
							z1++;
							a[i][4]=3;
						}
					}
				}
			}
		}
		if(q==1||u==2||o==3){
			int q1[100010],f;
			f=max(max(q,u),o);
			for(int i=1;i<=n;i++){
				q1[i]=a[i][f];
			}
			sort(q1+1,q1+n+1,cmp);
			
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=q1[i];
			}
			cout<<ans<<endl;
		}
		else{
			cout<<x+y+z<<endl;
		}
	}
}}
	
}
    return 0;
}
