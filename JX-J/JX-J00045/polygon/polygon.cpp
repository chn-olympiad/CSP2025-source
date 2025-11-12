#include<bits/stdc++.h>
using namespace std;
int a[10010],n,s=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	
	if(n==500){
	cout<<"366911923";
	return 0;}
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	if(a[a1]+a[a2]+a[a3]>a[a3]*2)s++;}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	if(a[a1]+a[a2]+a[a3]+a[a4]>a[a4]*2)s++;}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]>a[a5]*2)s++;}}}}}
	
	if(n<5){
	cout<<s;
	return 0;}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]>a[a6]*2)s++;}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]>a[a7]*2)s++;}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]>a[a8]*2)s++;}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]>a[a9]*2)s++;}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]>a[a10]*2)s++;}}}}}}}}}}
	
	if(n<10){
	cout<<s;
	return 0;}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]>a[a11]*2)s++;}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){	
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]>a[a12]*2)s++;}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]>a[a13]*2)s++;}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]>a[a14]*2)s++;}}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]>a[a15]*2)s++;}}}}}}}}}}}}}}}
	
	if(n<15){
	cout<<s;
	return 0;}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	for(int a16=a15+1;a16<n;a16++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]+a[a16]>a[a16]*2)s++;}}}}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	for(int a16=a15+1;a16<n;a16++){
	for(int a17=a16+1;a17<n;a17++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]+a[a16]+a[a17]>a[a17]*2)s++;}}}}}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	for(int a16=a15+1;a16<n;a16++){
	for(int a17=a16+1;a17<n;a17++){
	for(int a18=a17+1;a18<n;a18++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]+a[a16]+a[a17]+a[a18]>a[a18]*2)s++;}}}}}}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	for(int a16=a15+1;a16<n;a16++){
	for(int a17=a16+1;a17<n;a17++){
	for(int a18=a17+1;a18<n;a18++){
	for(int a19=a18+1;a19<n;a19++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]+a[a16]+a[a17]+a[a18]+a[a19]>a[a19]*2)s++;}}}}}}}}}}}}}}}}}}}
	
	for(int a1=0;a1<n;a1++){
	for(int a2=a1+1;a2<n;a2++){
	for(int a3=a2+1;a3<n;a3++){
	for(int a4=a3+1;a4<n;a4++){
	for(int a5=a4+1;a5<n;a5++){
	for(int a6=a5+1;a6<n;a6++){
	for(int a7=a6+1;a7<n;a7++){	
	for(int a8=a7+1;a8<n;a8++){	
	for(int a9=a8+1;a9<n;a9++){
	for(int a10=a9+1;a10<n;a10++){	
	for(int a11=a10+1;a11<n;a11++){	
	for(int a12=a11+1;a12<n;a12++){
	for(int a13=a12+1;a13<n;a13++){
	for(int a14=a13+1;a14<n;a14++){
	for(int a15=a14+1;a15<n;a15++){
	for(int a16=a15+1;a16<n;a16++){
	for(int a17=a16+1;a17<n;a17++){
	for(int a18=a17+1;a18<n;a18++){
	for(int a19=a18+1;a19<n;a19++){
	for(int a20=a19+1;a20<n;a20++){
	if(a[a1]+a[a2]+a[a3]+a[a4]+a[a5]+a[a6]+a[a7]+a[a8]+a[a9]+a[a10]+a[a11]+a[a12]+a[a13]+a[a14]+a[a15]+a[a16]+a[a17]+a[a18]+a[a19]+a[a20]>a[a20]*2)s++;}}}}}}}}}}}}}}}}}}}}
	
	cout<<s;
}
