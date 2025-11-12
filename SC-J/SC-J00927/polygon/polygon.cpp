#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin >>n;
	int o=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]==1) o++;
	}
	if(o==n){
		cout <<n-2;
		return 0;
	}
	sort(a+1,a+1+n);
	int m=0;
	if(n==1){
		cout <<0;
		return 0;
	}
	if(n==2){
		cout <<0;
		return 0;
	}
	if(n==3){
	   if(a[3]*2<=a[1]+a[2]+a[3]){
	   	cout <<1;
	   }
	   return 0;	
	}
	if(n>3){
		int l=0;
		for(int i=0;i<=1;i++){
			if(i==1)l=a[1];
			for(int i1=0;i1<=1;i1++){
				if(i1==1)l=a[2];
			for(int i2=0;i2<=1;i2++){
				if(i2==1)l=a[3];
			for(int i3=0;i3<=1;i3++){
				if(i3==1)l=a[4];
			for(int i4=0;i4<=1;i4++){
				if(i4==1)l=a[5];
			for(int i5=0;i5<=1;i5++){
				if(i5==1)l=a[6];
			for(int i6=0;i6<=1;i6++){
				if(i6==1)l=a[7];
			for(int i7=0;i7<=1;i7++){
				if(i7==1)l=a[8];
			for(int i8=0;i8<=1;i8++){
				if(i8==1)l=a[9];
			for(int i9=0;i9<=1;i++){ 
			if(i9==1)l=a[10];
				for(int i10=0;i10<=1;i10++){
					if(i10==1)l=a[11];
			for(int i11=0;i11<=1;i11++){
			if(i11==1)l=a[12];
			for(int i12=0;i12<=1;i12++){
				if(i12==1)l=a[13];
			for(int i13=0;i13<=1;i13++){
				if(i13==1)l=a[14];
			for(int i14=0;i14<=1;i14++){
				if(i14==1)l=a[15];
			for(int i15=0;i15<=1;i15++){
				if(i15==1)l=a[16];
			for(int i16=0;i16<=1;i16++){
				if(i16==1)l=a[17];
			for(int i17=0;i17<=1;i17++){
				if(i17==1)l=a[18];
			for(int i18=0;i18<=1;i18++){
				if(i18==1)l=a[19];
			for(int i19=0;i19<=1;i19++){
				if(i19==1)l=a[20];
				cout <<1;
			int o=i*a[1]+i1*a[2]+i2*a[3]+i3*a[4]+i4*a[5]+i5*a[6]+i6*a[7]+i7*a[8]+i8*a[9]+i9*a[10]+i10*a[11]+i11*a[12]+i12*a[13]+i13*a[14]+i14*a[15]+i15*a[16]+i16*a[17]+i17*a[18]+i18*a[19]+i19*a[20];
			if((i+i1+i2+i3+i4+i5+i6+i7+i8+i9+i10+i11+i2+i13+i14+i15+i16+i17+i18+i19)>=3&&l*2<o)
			m++;
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
	}
	cout <<m%998244353;
	return 0;
} 
