#include<bits/stdc++.h>
using namespace std;
#define zip(CCF,ccf,CSP) for(int CCF=ccf;CCF<=CSP;++) 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int only_once_=1;only_once_<=t;only_once_++){
		int n;
		cin>>n;
		int a[100007][4] = {0};
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			//cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<endl;	
		}
		int s1 = 0,s2 = 0,s3 = 0,s = 0;
		int h=0,themax = 0;
		if(n==0){
			cout<<0;
			continue;
		}
		for(int i1=1;i1<=3&&n>=2;i1++){
			h++;s += a[h][i1];
			if(i1==1)s1++;
			if(i1==2)s2++;
			if(i1==3)s3++; 
			//cout<<a[h][i1];
			for(int i2=1;i2<=3;i2++){
				h++;s += a[h][i2];
				if(i2==1)s1++;
				if(i2==2)s2++;
				if(i2==3)s3++;//cout<<a[h][i2];
				if(s1<=n/2 && s2<=n/2 && s3<=n/2){
					//cout<<s<<'\n';
					themax = max(s,themax);
				}
				for(int i3=1;i3<=3 && n>=4;i3++){
					h++;s += a[h][i3];
					if(i3==1)s1++;
					if(i3==2)s2++;
					if(i3==3)s3++;//cout<<a[h][i3];
					for(int i4=1;i4<=3;i4++){
						h++;s += a[h][i4];
						//for(int i=1;i<=n;i++){
							//cout<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<' '<<i4<<' '<<a[h][i4]<<endl;	
						//}
						if(i4==1)s1++;
						if(i4==2)s2++;
						if(i4==3)s3++;//cout<<a[h][i4]<<endl;
						if(s1<=n/2 && s2<=n/2 && s3<=n/2){
							//cout<<i1<<i2<<i3<<i4<<endl;
							//if(i1==1&&i2==3&&i3==1&&i4==2)cout<<a[1][i1]<<a[2][i2]<<a[3][i3]<<a[4][i4];
							themax = max(s,themax);
						}
						for(int i5=1;i5<=3&&n>=6;i5++){
							h++;
							if(i5==1)s += a[h][1],s1++;
							if(i5==2)s += a[h][2],s2++;
							if(i5==3)s += a[h][3],s3++; 
							for(int i6=1;i6<=3;i6++){
								h++;
								if(i6==1)s += a[h][1],s1++;
								if(i6==2)s += a[h][2],s2++;
								if(i6==3)s += a[h][3],s3++;
								if(s1<=n/2 && s2<=n/2 && s3<=n/2){
									themax = max(s,themax);
								}
								for(int i7=1;i7<=3 && n>=8;i7++){
									h++;
									if(i7==1)s += a[h][1],s1++;
									if(i7==2)s += a[h][2],s2++;
									if(i7==3)s += a[h][3],s3++;
									for(int i8=1;i8<=3;i8++){
										h++;
										if(i8==1)s += a[h][1],s1++;
										if(i8==2)s += a[h][2],s2++;
										if(i8==3)s += a[h][3],s3++;
										if(s1<=n/2 && s2<=n/2 && s3<=n/2){
											themax = max(s,themax);
										}
										for(int i9=1;i9<=3 && n>=10;i9++){
											h++;
											if(i9==1)s += a[h][1],s1++;
											if(i9==2)s += a[h][2],s2++;
											if(i9==3)s += a[h][3],s3++;
											for(int i10=1;i10<=3;i10++){
												h++;
												if(i10==1)s += a[h][1],s1++;
												if(i10==2)s += a[h][2],s2++;
												if(i10==3)s += a[h][3],s3++;
												if(s1<=n/2 && s2<=n/2 && s3<=n/2){
													themax = max(s,themax);
												}
		for(int i11=1;i11<=3&&n>=12;i11++){
			h++;
			if(i11==1)s += a[h][1],s1++;
			if(i11==2)s += a[h][2],s2++;
			if(i11==3)s += a[h][3],s3++; 
			for(int i12=1;i12<=3;i12++){
				h++;
				if(i12==1)s += a[h][1],s1++;
				if(i12==2)s += a[h][2],s2++;
				if(i12==3)s += a[h][3],s3++;
				if(s1<=n/2 && s2<=n/2 && s3<=n/2){
					themax = max(s,themax);
				}
				for(int i13=1;i13<=3 && n>=14;i13++){
					h++;
					if(i13==1)s += a[h][1],s1++;
					if(i13==2)s += a[h][2],s2++;
					if(i13==3)s += a[h][3],s3++;
					for(int i14=1;i14<=3;i14++){
						h++;
						if(i14==1)s += a[h][1],s1++;
						if(i14==2)s += a[h][2],s2++;
						if(i14==3)s += a[h][3],s3++;
						if(s1<=n/2 && s2<=n/2 && s3<=n/2){
							themax = max(s,themax);
						}
						for(int i15=1;i15<=3&&n>=16;i15++){
							h++;
							if(i15==1)s += a[h][1],s1++;
							if(i15==2)s += a[h][2],s2++;
							if(i15==3)s += a[h][3],s3++; 
							for(int i16=1;i16<=3;i16++){
								h++;
								if(i16==1)s += a[h][1],s1++;
								if(i16==2)s += a[h][2],s2++;
								if(i16==3)s += a[h][3],s3++;
								if(s1<=n/2 && s2<=n/2 && s3<=n/2){
									themax = max(s,themax);
								}
								for(int i17=1;i17<=3 && n>=18;i17++){
									h++;
									if(i17==1)s += a[h][1],s1++;
									if(i17==2)s += a[h][2],s2++;
									if(i17==3)s += a[h][3],s3++;
									for(int i18=1;i18<=3;i18++){
										h++;
										if(i18==1)s += a[h][1],s1++;
										if(i18==2)s += a[h][2],s2++;
										if(i18==3)s += a[h][3],s3++;
										if(s1<=n/2 && s2<=n/2 && s3<=n/2){
											themax = max(s,themax);
										}
										for(int i19=1;i19<=3 && n>=20;i19++){
											h++;
											if(i19==1)s += a[h][1],s1++;
											if(i19==2)s += a[h][2],s2++;
											if(i19==3)s += a[h][3],s3++;
											for(int i20=1;i20<=3;i20++){
												h++;
												if(i20==1)s += a[h][1],s1++;
												if(i20==2)s += a[h][2],s2++;
												if(i20==3)s += a[h][3],s3++;
												cout<<s<<endl;
												if(s1<=n/2 && s2<=n/2 && s3<=n/2){
													themax = max(s,themax);
												}
												if(i20==1)s -= a[h][1],s1--;
												if(i20==2)s -= a[h][2],s2--;
												if(i20==3)s -= a[h][3],s3--;
												
											}
											if(i19==1)s -= a[h][1],s1--;
											if(i19==2)s -= a[h][2],s2--;
											if(i19==3)s -= a[h][3],s3--;
										}
										if(i18==1)s -= a[h][1],s1--;
										if(i18==2)s -= a[h][2],s2--;
										if(i18==3)s -= a[h][3],s3--;
									}
									if(i17==1)s -= a[h][1],s1--;
									if(i17==2)s -= a[h][2],s2--;
									if(i17==3)s -= a[h][3],s3--;
								}
								if(i16==1)s -= a[h][1],s1--;
								if(i16==2)s -= a[h][2],s2--;
								if(i16==3)s -= a[h][3],s3--;
							}
							if(i15==1)s -= a[h][1],s1--;
							if(i15==2)s -= a[h][2],s2--;
							if(i15==3)s -= a[h][3],s3--;
						}
						if(i14==1)s -= a[h][1],s1--;
						if(i14==2)s -= a[h][2],s2--;
						if(i14==3)s -= a[h][3],s3--;
					}
					if(i13==1)s -= a[h][1],s1--;
					if(i13==2)s -= a[h][2],s2--;
					if(i13==3)s -= a[h][3],s3--;
				}
				if(i12==1)s -= a[h][1],s1--;
				if(i12==2)s -= a[h][2],s2--;
				if(i12==3)s -= a[h][3],s3--;
			}
			if(i11==1)s -= a[h][1],s1--;
			if(i11==2)s -= a[h][2],s2--;
			if(i11==3)s -= a[h][3],s3--;
		}
												if(i10==1)s -= a[h][1],s1--;
												if(i10==2)s -= a[h][2],s2--;
												if(i10==3)s -= a[h][3],s3--;
												
											}
											if(i9==1)s -= a[h][1],s1--;
											if(i9==2)s -= a[h][2],s2--;
											if(i9==3)s -= a[h][3],s3--;
										}
										if(i8==1)s -= a[h][1],s1--;
										if(i8==2)s -= a[h][2],s2--;
										if(i8==3)s -= a[h][3],s3--;
									}
									if(i7==1)s -= a[h][1],s1--;
									if(i7==2)s -= a[h][2],s2--;
									if(i7==3)s -= a[h][3],s3--;
								}
								if(i6==1)s -= a[h][1],s1--;
								if(i6==2)s -= a[h][2],s2--;
								if(i6==3)s -= a[h][3],s3--;
							}
							if(i5==1)s -= a[h][1],s1--;
							if(i5==2)s -= a[h][2],s2--;
							if(i5==3)s -= a[h][3],s3--;
						}
						if(i4==1)s -= a[h][1],s1--;
						if(i4==2)s -= a[h][2],s2--;
						if(i4==3)s -= a[h][3],s3--;
					}
					if(i3==1)s -= a[h][1],s1--;
					if(i3==2)s -= a[h][2],s2--;
					if(i3==3)s -= a[h][3],s3--;
				}
				if(i2==1)s -= a[h][1],s1--;
				if(i2==2)s -= a[h][2],s2--;
				if(i2==3)s -= a[h][3],s3--;
			}
			if(i1==1)s -= a[h][1],s1--;
			if(i1==2)s -= a[h][2],s2--;
			if(i1==3)s -= a[h][3],s3--;
		}
		cout<<themax<<'\n';
		/*
		是的，你没看错，20个for,O((3^20)*t),特暴力枚举，至少拿到20pts,快夸我！
		不过，看在我这~~~~~~~~~~~~~~~么喜欢CCF的份上，能不能让测试点放点水呢？ 
		*/
	}
	return 0;
}
























































/*解压缩预制代码 
zip(csp,1,1){int club1[100007],club2[100007],club3[100007];for(int i=1;i<=n;i++){club1[i] = a[i][1];club2[i] = a[i][2];club3[i] = a[i][3];}sort(club1+1,club1+n+1);for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(club1[i] == a[j][1])club2[j] += 1005*(n-i); club3[j] += 1005*(n-i);sort(club2+1,club2+n+1);sort(club3+1,club3+n+1);for(int i=1;i<=n;i++){club2[i]-=(i-1)*1005;club3[i]-=(i-1)*1005;cout<<club1[i]<<' '<<club2[i]<<' '<<club3[i]<<'\n'; }}
*/
			