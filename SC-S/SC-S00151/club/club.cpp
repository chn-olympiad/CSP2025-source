#include <bits/stdc++.h>
const int N = 200 + 9;
int t, n, a[N][3], f[N][N][N], w[N][N][N], v[N][N][N];
void tsk1() {
//	printf("f[1][0][1] = %d, a[1][1] = %d\n", f[1][0][1], a[1][1]);
	for(int i = 2; i <= n; i++) {
//		printf("f[1][0][1] = %d\n", f[1][0][1]);
//		printf("a[1][1] = %d\n", a[1][1]);
		for(int k1 = 0; k1 <= i; k1++) {
			for(int k2 = 0; k2 <= i - k1; k2++) {
				int k3 = i - k1 - k2, x1, x2;
				f[i][k1][k2] = 0, v[i][k1][k2] = t + 1;
				if(k1 - 1 >= 0) {
					f[i][k1][k2] = std::max(f[i][k1][k2], f[i - 1][k1 - 1][k2] + a[i][0]);
					x1 = f[i - 1][k1 - 1][k2] + a[i][0];
//					printf("x1 = %d + %d\n",f[i - 1][k1 - 1][k2], a[i][0]);
//					printf("f = %d\n", f[i][k1][k2]);
				}
				if(k2 - 1 >= 0) {
					f[i][k1][k2] = std::max(f[i][k1][k2], f[i - 1][k1][k2 - 1] + a[i][1]);
					x2 = f[i - 1][k1][k2 - 1] + a[i][1];
//					printf("x2 = %d + %d\n",f[i - 1][k1][k2 - 1], a[i][1]);
//					printf("f = %d\n", f[i][k1][k2]);
				}
				if(k3 - 1 >= 0) {
					f[i][k1][k2] = std::max(f[i][k1][k2], f[i - 1][k1][k2] + a[i][2]);
//					printf("x3 = %d + %d\n",f[i - 1][k1][k2], a[i][2]);
//					printf("f = %d\n", f[i][k1][k2]);
//					x3 = f[i - 1][k1][k2] + a[i][2];
				}
				
				if(f[i][k1][k2] == x1) w[i][k1][k2] = 0;
				else if(f[i][k1][k2] == x2) w[i][k1][k2] = 1;
				else w[i][k1][k2] = 2;
			}
		}
	}
//	printf("f[1][0][1][0] = %d\n", f[1][0][1]);
//	printf("a[1][1] = %d\n", a[1][1]);
	int ans = 0, q1, q2;
	for(int i = 0; i <= n / 2; i++) {
		for(int j = 0; j <= std::min(n - i, n / 2); j++) if(n - i - j <= n / 2) {
			ans = std::max(ans, f[n][i][j]);
			if(ans == f[n][i][j]) q1 = i, q2 = j;
		}
	}
	printf("%d\n", ans);
	q1 = 1, q2 = 3;
	for(int i = 9; i >= 1; i--) {
//		printf("stu%d: %d\n", i, a[i][w[i][q1][q2]]);
		if(w[i][q1][q2] == 0) q1--;
		else if(w[i][q1][q2] == 1) q2--;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out","w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
//		printf("a[1][1] = %d\n", a[1][1]);
		f[1][1][0] = a[1][0], f[1][0][1] = a[1][1], f[1][0][0] = a[1][2];
//		printf("f[1][0][1] = %d\n", f[1][0][1]);
		tsk1();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
bon yoyage
your mermaid's setting sail
at last
full speed towards your heart
full speed towards your heart

i had enough
i'm reclaiming myself
the aft
leaving behind the hurt
leaving behing the hurt

when it snapped
my compass was swallowed by the sea
my compass was swallowed by the sea
i cursed this relationship between 
you and me
i wanted blood
i wanted black and white

clear cut
your evils predefinded
your evils predefinded

hold on tight
my compass is curiosity
my compass is curiosity
i percing through the rope that strangled
you and me
let us be free

high tide
low tide
high tide
low tide
high tide
low tide
*/
/*
open the curtains
lights on
don't miss a moment of this
experiment

oh, the book is strange
like clock-work orange 
keep your eyes buttered till the end

which you are you going to be
ohh
inside the mirror do you see
ahh-ah
someone else in that body
dance for me

one and
two and
three and
sit there stright like a doggy
till i finish my read

cut it off cut down your loss
all that stubborn loyalty
...
yes i'll be your merionette
here tug on my threads
show them my dolly pink snow white artifital beauty
maybe we're all cool machines
stuffed to the human's skin
with human's sins
sewed by the god of the city
...

*/
/*
i walk down a path
leading to the past
stolen from tree's hands
a regreter's friend--the forbidden fruit
i bite off it's skin
chewing on it's tender flesh
quaff down it's luakwarm pus
i become the me who i despired
we swallow the time let us rewind

lament
if you wanted me to speak
if you wanted me to think
if you wanted me to carry on our dreams
each loop we live through
each loop we live through
the standerds inside me
the line i drew for me
lowers to the earth

lament
why do you make my voice slutter
why do truth never matter
why do you curse me with you're a natural-born genius
endless inferno
inferno
counter clock we load
counter clode we reload

tick tick tock
endless clock
forget me not
i'm inside the empathic lights

i bite off your skin
exposing the angels on your ribs
they stared at us
hello how may i help you today
please a one-way ticket to heaven

packed up on velvet seats
seneries were passing by
not so different from our hell
not so different from our home

then i realized someone's heaven
could be the sourse of my tornent
life if allowing yourself
allowing yourself 
to step on fire

life is it to consume
life is to become food for each other
no matter evil or good
life is 
fairness
life is inequality
life is in the motion
we live by default

lament
if you want me to forget
if you want me to forgive
if you want we to pretend we're civilized human
each loop we die through
each loop we die through
the ego fending me
rashinlize my sin

lament
why do death end my torture
why don't anyone feel my hurt
why do you crown the most violent to be champion
endless inferno
inferno
we built for ourselves
reflesh other in this hell
*/
/*
AFO快乐！
t2好像有点思路
算了估计写不完
。。。我好菜
*/